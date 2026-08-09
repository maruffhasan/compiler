lexer grammar Lexer;

INT : [0-9]+ ;
PLUS : '+';
TIMES : '*';
LPAREN : '(';
RPAREN : ')';
WHITESPACE : [ \r\n]+ -> skip;
