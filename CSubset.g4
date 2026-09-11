grammar CSubset;
import Lexer;

start : program ;

program
    : program unit      # ProgramUnit
    | unit              # ProgramSingleUnit
    ;

unit
    : var_declaration    # UnitVarDecl
    | func_declaration   # UnitFuncDecl
    | func_definition    # UnitFuncDef
    ;

func_declaration
    : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON   # FuncDeclWithParams
    | type_specifier ID LPAREN RPAREN SEMICOLON                  # FuncDeclNoParams
    ;

func_definition
    : type_specifier ID LPAREN parameter_list RPAREN compound_statement  # FuncDefWithParams
    | type_specifier ID LPAREN RPAREN compound_statement                 # FuncDefNoParams
    ;

parameter_list
    : parameter_list COMMA type_specifier ID     # ParamListMultiNamed
    | parameter_list COMMA type_specifier        # ParamListMultiUnnamed
    | type_specifier ID                          # ParamListSingleNamed
    | type_specifier                             # ParamListSingleUnnamed
    ;

compound_statement
    : LCURL statements RCURL     # CompoundWithStmts
    | LCURL RCURL                # CompoundEmpty
    ;

var_declaration
    : type_specifier declaration_list SEMICOLON    # VarDecl
    ;

type_specifier
    : INT            # TypeInt
    | FLOAT          # TypeFloat
    | VOID           # TypeVoid
    ;

declaration_list
    : declaration_list COMMA ID                            # DeclListCommaId
    | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD    # DeclListCommaIdArray
    | ID                                                   # DeclListSingleId
    | ID LTHIRD CONST_INT RTHIRD                           # DeclListSingleIdArray
    ;

statements
    : statement              # StatementsSingle
    | statements statement   # StatementsMulti
    ;

statement
    : var_declaration                                                      # StmtVarDecl
    | expression_statement                                                                 # StmtExprStmt
    | compound_statement                                                   # StmtCompound
    | FOR LPAREN expression_statement expression_statement expression RPAREN statement    # StmtFor
    | IF LPAREN expression RPAREN statement                                # StmtIf
    | IF LPAREN expression RPAREN statement ELSE statement                 # StmtIfElse
    | WHILE LPAREN expression RPAREN statement                             # StmtWhile
    | PRINTLN LPAREN ID RPAREN SEMICOLON                                   # StmtPrintln
    | RETURN expression SEMICOLON                                          # StmtReturn
    ;

expression_statement
    : SEMICOLON                # ExprStmtEmpty
    | expression SEMICOLON     # ExprStmtExpr
    ;

variable
    : ID                              # VarSimple
    | ID LTHIRD expression RTHIRD     # VarArray
    ;

expression
    : logic_expression                         # ExprLogic
    | variable ASSIGNOP logic_expression       # ExprAssign
    ;

logic_expression
    : rel_expression                           # LogicSingle
    | rel_expression LOGICOP rel_expression    # LogicOp
    ;

rel_expression
    : simple_expression                           # RelSingle
    | simple_expression RELOP simple_expression   # RelOp
    ;

simple_expression
    : term                              # SimpleTerm
    | simple_expression ADDOP term      # SimpleAddOp
    ;

term
    : unary_expression              # TermUnary
    | term MULOP unary_expression   # TermMulOp
    ;

unary_expression
    : ADDOP unary_expression    # UnaryAddOp
    | NOT unary_expression      # UnaryNot
    | factor                    # UnaryFactor
    ;

factor
    : variable                        # FactorVar
    | ID LPAREN argument_list RPAREN  # FactorFuncCall
    | LPAREN expression RPAREN        # FactorParen
    | CONST_INT                       # FactorConstInt
    | CONST_FLOAT                     # FactorConstFloat
    | variable INCOP                  # FactorIncop
    | variable DECOP                  # FactorDecop
    ;

argument_list
    : arguments   # ArgListNonEmpty
    |             # ArgListEmpty
    ;

arguments
    : arguments COMMA logic_expression   # ArgumentsMulti
    | logic_expression                   # ArgumentsSingle
    ;