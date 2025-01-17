grammar Smplang;

// Parser
program: structDecl* functionDecl* statement*;

functionDecl: FUNC returnType ID LPAREN parameterList? RPAREN block;
returnType: type | VOID;
parameterList: parameter (COMMA parameter)*;
parameter: type ID;

structDecl: STRUCT structType LBRACE fieldDecl+ RBRACE SEMI;
fieldDecl: type ID SEMI;

type: primitiveType | type ARRAYTYPE | structType;
primitiveType: 'int' | 'double' | 'char' | 'bool';
structType: ID;

block: LBRACE statement* RBRACE;

statement:
    varDecl SEMI
    | assignment SEMI
    | returnStatement SEMI
    | expression SEMI
    | ifStatement
    | whileStatement;
//    | breakStatement SEMI
//    | continueStatement SEMI;

varDecl: type ID (ASSIGN expression)?;
assignment: assignable ASSIGN expression;

ifStatement: ifBlock (elifBlock)* (elseBlock)?;
ifBlock: IF LPAREN expression RPAREN (statement | block);
elifBlock: ELIF LPAREN expression RPAREN (statement | block);
elseBlock: ELSE (statement | block);
whileStatement: WHILE LPAREN expression RPAREN (statement | block);

//breakStatement: BREAK;
//continueStatement: CONTINUE;

returnStatement: RETURN expression?;

expression:
      LPAREN expression RPAREN
    | NEG expression
    | NOT expression
    | expression MULT expression
    | expression ADD expression
    | expression COMPOP expression
    | expression AND expression
    | expression OR expression
    | primaryExpression;

primaryExpression:
      ID
    | primaryExpression DOT ID
    | primaryExpression LBRACK expression RBRACK
    | functionCall
    | INT
    | DOUBLE
    | CHAR
    | BOOL
    | NULL_VALUE
    | LPAREN expression RPAREN
    | arrayInit;
//    | structInit;

arrayInit: LBRACE (expression (COMMA expression)*)? RBRACE;
//structInit: ID LPAREN argumentList? RPAREN;
argumentList: expression (COMMA expression)*;
//structureInitList: ID COLON expression (COMMA ID COLON expression)*;

functionCall: ID LPAREN argumentList? RPAREN;
assignable: ID | (assignablePrefix (DOT ID | LBRACK expression RBRACK));
assignablePrefix:
    ID
  | assignablePrefix DOT ID
  | assignablePrefix LBRACK expression RBRACK;

// Lexer
FUNC: 'func';
VOID: 'void';
NULL_VALUE: 'null';
RETURN: 'return';
FOR: 'for';
//PRINT: 'print';
WHILE: 'while';
IF: 'if';
ELSE: 'else';
ELIF: 'elif';
STRUCT: 'struct';
BREAK: 'break';
CONTINUE: 'continue';

BOOL: 'true' | 'false';
INT: [0-9]+;
DOUBLE: [0-9]+ DOT [0-9]*;
CHAR: '\'' (~[\b\t\r\n'"\\]|'\\'['"\\anbrvt]) '\'';
ID: [a-zA-Z_][a-zA-Z_0-9]*;

NEG: '--';
MULT: '*' | '/' | '%';
ADD: '+' | '-';
COMPOP: '==' | '!=' | '<' | '>' | '<=' | '>=';
NOT: '!';
AND: '&&';
OR: '||';
ASSIGN: '=';
LPAREN: '(';
RPAREN: ')';
LBRACE: '{';
RBRACE: '}';
LBRACK: '[';
RBRACK: ']';
ARRAYTYPE: '[]';
SEMI: ';';
COMMA: ',';
//COLON: ':';
DOT: '.';

WS: [ \t\r\n]+ -> skip;
COMMENT: '//' ~[\r\n]* -> skip;