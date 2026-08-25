grammar CSubset;
import Lexer;


start : program EOF ;

program
    : program unit
    | unit
    ;

unit
    : var_declaration
    | func_definition
    ;

func_definition
    : type_specifier ID LPAREN RPAREN compound_statement               # FuncDefNoParams
    ;

compound_statement
    : LCURL statements RCURL # CompoundStmtBody
    | LCURL RCURL            # CompoundStmtEmpty
    ;

var_declaration
    : type_specifier declaration_list SEMICOLON # VarDecl
    ;

type_specifier
    : INT   # TypeInt
    | VOID  # TypeVoid
    ;

declaration_list
    : declaration_list COMMA ID                        # DeclListCommaId
    | ID                                               # DeclListSingleId
    ;

statements
    : statement            # StmtSingle
    | statements statement # StmtSeq
    ;

statement
    : var_declaration                                                     # StmtVarDecl
    | expression_statement                                                # StmtExpr
    | compound_statement                                                  # StmtCompound
    | PRINTLN LPAREN ID RPAREN SEMICOLON                                  # StmtPrintln
    | RETURN expression SEMICOLON                                         # StmtReturn
    ;

expression_statement
    : SEMICOLON            # ExprStmtEmpty
    | expression SEMICOLON # ExprStmtExpr
    ;

variable
    : ID                         # VarSimple
    ;

expression
    : logic_expression                         # ExprLogic
    | variable ASSIGNOP logic_expression       # ExprAssign
    ;

logic_expression
    : rel_expression                           # LogicRel
    | rel_expression LOGICOP rel_expression   # LogicOp
    ;

rel_expression
    : simple_expression                        # RelSimple
    | simple_expression RELOP simple_expression # RelOp
    ;

simple_expression
    : term                                     # SimpleTerm
    | simple_expression ADDOP term             # SimpleAddOp
    ;

term
    : unary_expression                         # TermUnary
    | term MULOP unary_expression              # TermMulOp
    ;

unary_expression
    : ADDOP unary_expression                   # UnaryAddOp
    | NOT unary_expression                     # UnaryNot
    | factor                                   # UnaryFactor
    ;

factor
    : variable                       # FactorVar
    | LPAREN expression RPAREN       # FactorParen
    | CONST_INT                      # FactorConstInt
    | CONST_FLOAT                    # FactorConstFloat
    | variable INCOP                 # FactorIncop
    | variable DECOP                 # FactorDecop
    ;