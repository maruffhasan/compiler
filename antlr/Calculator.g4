grammar Calculator;
import Lexer;

start : expression;
expression : expression PLUS term # Plus
            |
            term                  # ExprTerm
            ;
term : term TIMES f=factor          # Times
    | factor                      # TermFact
    ;
factor : LPAREN expression RPAREN # Paren
        |
         INT                      # FactorInt
         ;
