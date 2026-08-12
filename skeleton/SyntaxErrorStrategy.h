#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <set>
#include "antlr4-runtime.h"
#include "CSubsetParser.h"

// Total syntax errors found; main.cpp adds this to visitor.getErrorCount()
// for the "Total Errors" line.
extern int syntaxErrorCount;

// ---------------------------------------------------------------------
// CSubsetErrorStrategy
//
// Replaces ANTLR's default recovery messages with the project's custom
// format:  "Error at line N: syntax error, <message>"
//
// It handles three distinct recovery shapes seen in error5.txt / log5.txt:
//
//   1) Extra/garbage tokens right before a single required closing token
//      (e.g. RPAREN) -> "unexpected token(s) '<span>' before '<tok>'"
//
//   2) Extra/garbage tokens inside a "list" rule (declaration_list,
//      parameter_list, arguments) where the follow set has more than one
//      option (COMMA to continue, or a terminator) -> "unexpected
//      token(s) '<span>' in <list name>"
//
//   3) A missing ';' terminating expression_statement -> "missing ';'
//      after expression '<text>'" (uses default single-token insertion
//      so parsing just continues with the next token as a new statement)
//
//   4) An operator appearing where an operand was expected right after
//      ADDOP/MULOP (e.g. "2 + = 6") -> "invalid operand '<tok>' after
//      '<prevTok>'", followed by panic-mode recovery that discards
//      tokens up to the next thing that can start a fresh
//      statement/expression (SEMICOLON, ID, CONST_INT, CONST_FLOAT,
//      LPAREN, RCURL, EOF). This intentionally drops the whole botched
//      sub-expression rather than trying to patch it back together,
//      matching the log5.txt trace where "2 + = 6" becomes two separate
//      statements: "a=2" (missing ';') and "6" (missing ';').
// ---------------------------------------------------------------------
class CSubsetErrorStrategy : public antlr4::DefaultErrorStrategy {
public:
    CSubsetErrorStrategy(std::ofstream &log, std::ofstream &err)
        : logFile(log), errorFile(err) {}

    // ---- Case 1 & 2 & 3: handled at single-token-mismatch recovery ----
    antlr4::Token* recoverInline(antlr4::Parser *recognizer) override {
        using namespace antlr4;

        antlr4::RuleContext *ctx = recognizer->getContext();
        misc::IntervalSet expecting = recognizer->getExpectedTokens();

        // --- Case 3: missing ';' after a fully-parsed expression ---
        if (isRule(ctx, CSubsetParser::RuleExpression_statement) &&
            expecting.contains(CSubsetParser::SEMICOLON)) {

            auto *esCtx = dynamic_cast<CSubsetParser::Expression_statementContext *>(ctx);
            std::string exprText =
                (esCtx && esCtx->expression()) ? esCtx->expression()->getText() : "";
            int line = recognizer->getCurrentToken()->getLine();

            logSyntaxError(line, "missing ';' after expression '" + exprText + "'");

            // Let the default machinery actually perform the (virtual)
            // token insertion so the rule completes and parsing resumes
            // at the next token as a fresh statement.
            return DefaultErrorStrategy::recoverInline(recognizer);
        }

        // --- Case 1 & 2: skip a short run of unexpected tokens ---
        std::string listName = enclosingListName(ctx);

        antlr4::TokenStream *input = recognizer->getInputStream();
        std::vector<antlr4::Token *> skipped;
        const size_t MAX_SKIP = 8;

        while (skipped.size() < MAX_SKIP) {
            antlr4::Token *la = input->LT(1 + (ssize_t)skipped.size());
            if (la == nullptr || la->getType() == antlr4::Token::EOF) break;
            if (expecting.contains(la->getType())) break;
            // Hard stops so we never eat past a statement/block boundary.
            if (la->getType() == CSubsetParser::SEMICOLON ||
                la->getType() == CSubsetParser::LCURL ||
                la->getType() == CSubsetParser::RCURL) break;
            skipped.push_back(la);
        }

        if (!skipped.empty()) {
            std::string span;
            for (size_t i = 0; i < skipped.size(); i++) {
                if (i) span += " ";
                span += skipped[i]->getText();
            }
            int line = skipped[0]->getLine();

            if (!listName.empty()) {
                logSyntaxError(line, "unexpected token(s) '" + span + "' in " + listName);
            } else {
                std::string expectedText = expectedTokenDisplay(recognizer, expecting);
                logSyntaxError(line, "unexpected token(s) '" + span + "' before " + expectedText);
            }

            for (size_t i = 0; i < skipped.size(); i++) recognizer->consume();
        }

        // Whatever's left, let ANTLR try its normal single-token
        // insertion/deletion so the rule can still complete.
        return DefaultErrorStrategy::recoverInline(recognizer);
    }

    // ---- Case 4: operator-after-operator, panic-mode recovery ----
    void recover(antlr4::Parser *recognizer, std::exception_ptr /*e*/) override {
        antlr4::TokenStream *input = recognizer->getInputStream();
        antlr4::Token *bad = recognizer->getCurrentToken();
        antlr4::Token *prev = input->size() > 0 ? input->LT(-1) : nullptr;

        if (prev != nullptr && isOperatorToken(bad->getType()) &&
            (prev->getType() == CSubsetParser::ADDOP || prev->getType() == CSubsetParser::MULOP)) {
            logSyntaxError(bad->getLine(),
                "invalid operand '" + bad->getText() + "' after '" + prev->getText() + "'");
        } else {
            // Fallback: not a pattern we specifically recognize — still
            // report *something* so errors are never silently swallowed.
            logSyntaxError(bad->getLine(), "unexpected token '" + bad->getText() + "'");
        }

        // Discard tokens until we reach something that can plausibly
        // start a new statement/expression, or a block/EOF boundary.
        while (true) {
            size_t t = recognizer->getInputStream()->LA(1);
            if (t == antlr4::Token::EOF ||
                t == CSubsetParser::SEMICOLON ||
                t == CSubsetParser::RCURL) break;
            if (t == CSubsetParser::CONST_INT || t == CSubsetParser::CONST_FLOAT ||
                t == CSubsetParser::ID || t == CSubsetParser::LPAREN) break;
            recognizer->consume();
        }
    }

private:
    std::ofstream &logFile;
    std::ofstream &errorFile;

    void logSyntaxError(int line, const std::string &msg) {
        syntaxErrorCount++;
        std::string full = "Error at line " + std::to_string(line) + ": syntax error, " + msg;
        errorFile << full << "\n\n";
        logFile << full << "\n\n";
    }

    static bool isRule(antlr4::RuleContext *ctx, size_t ruleIndex) {
        return ctx != nullptr && ctx->getRuleIndex() == ruleIndex;
    }

    // Walks up from the failure point to see whether we're inside one of
    // the "list" rules, where the follow set is ambiguous (COMMA to
    // continue vs. a terminator), so we phrase the message as
    // "in <list name>" instead of "before '<token>'".
    static std::string enclosingListName(antlr4::RuleContext *ctx) {
        while (ctx != nullptr) {
            size_t idx = ctx->getRuleIndex();
            if (idx == CSubsetParser::RuleDeclaration_list) return "declaration list";
            if (idx == CSubsetParser::RuleParameter_list) return "parameter list";
            if (idx == CSubsetParser::RuleArguments || idx == CSubsetParser::RuleArgument_list)
                return "argument list";
            ctx = ctx->parent;
        }
        return "";
    }

    static bool isOperatorToken(size_t type) {
        static const std::set<size_t> ops = {
            CSubsetParser::ADDOP, CSubsetParser::MULOP, CSubsetParser::ASSIGNOP,
            CSubsetParser::RELOP, CSubsetParser::LOGICOP, CSubsetParser::NOT
        };
        return ops.count(type) > 0;
    }

    // Uses the grammar's literal token text (e.g. RPAREN's literal is
    // "')'") so "before " + this reads naturally as "before ')'".
    static std::string expectedTokenDisplay(antlr4::Parser *recognizer,
                                             const antlr4::misc::IntervalSet &expecting) {
        if (expecting.isNil()) return "<EOF>";
        auto list = expecting.toList();
        if (list.empty()) return "<EOF>";
        std::string lit = recognizer->getVocabulary().getLiteralName(list[0]);
        if (!lit.empty()) return lit;
        std::string sym = recognizer->getVocabulary().getSymbolicName(list[0]);
        return sym.empty() ? "<token>" : sym;
    }
};