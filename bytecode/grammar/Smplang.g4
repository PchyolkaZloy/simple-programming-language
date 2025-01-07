grammar Smplang;

// Parser
program: (functionDecl | structDecl | statement)* EOF;

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
    | whileStatement
    | breakStatement SEMI
    | continueStatement SEMI;

varDecl: type ID (ASSIGN expression)?;
assignment: assignable ASSIGN expression;

ifStatement: IF LPAREN expression RPAREN (statement | block) (ELIF LPAREN expression RPAREN (statement | block))* (ELSE (statement | block))?;
whileStatement: WHILE LPAREN expression RPAREN (statement | block);

breakStatement: BREAK;
continueStatement: CONTINUE;

returnStatement: RETURN expression?;
//printStatement: PRINT LPAREN expression RPAREN;

expression:
      LPAREN expression RPAREN
    | NEG expression
    | NOT expression
    | expression AND expression
    | expression OR expression
    | expression MULT expression
    | expression ADD expression
    | expression COMPOP expression
    | primaryExpression
    | expression LBRACK expression RBRACK
    ;

primaryExpression:
      ID
    | fieldAccess
    | arrayAccess
    | functionCall
    | INT
    | DOUBLE
    | CHAR
    | BOOL
    | LPAREN expression RPAREN
    | arrayInit
    | structInit;

arrayInit: LBRACE (expression (COMMA expression)*)? RBRACE;
structInit: ID LPAREN argumentList? RPAREN;
argumentList: expression (COMMA expression)*;

fieldAccess: ID (DOT ID)+;
arrayAccess: ID LBRACK expression RBRACK;
functionCall: ID LPAREN argumentList? RPAREN;
assignable: ID | fieldAccess | arrayAccess;

// Lexer
FUNC: 'func';
VOID: 'void';
RETURN: 'return';
FOR: 'for';
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
CHAR: '\'' . '\'';
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
DOT: '.';

WS: [ \t\r\n]+ -> skip;
COMMENT: '//' ~[\r\n]* -> skip;