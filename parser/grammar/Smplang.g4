grammar Smplang;

// Parser
program: (function | structDecl | statement)*;

function: FUNC returnType ID LPAREN parameterList? RPAREN block;
returnType: type | VOID;
parameterList: parameter (COMMA parameter)*;
parameter: type ID;

structDecl: STRUCT structType LBRACE fieldDecl+ RBRACE SEMI;
fieldDecl: type ID SEMI;

type: primitiveType | type LBRACK INT RBRACK | structType;
primitiveType: 'int' | 'double' | 'char' | 'bool';
structType: ID;

block: LBRACE statement* RBRACE;

statement: varDecl SEMI
          | assignment SEMI
          | returnStatement SEMI
          | printStatement SEMI
          | expression SEMI
          | ifStatement
          | whileStatement
          | forStatement
          | block;

varDecl: type ID (ASSIGN expression)?;
assignment: assignable ASSIGN expression;

ifStatement: IF LPAREN expression RPAREN statement (ELSE statement)?;
whileStatement: WHILE LPAREN expression RPAREN statement;
forStatement: FOR LPAREN varDecl SEMI expression SEMI assignment RPAREN statement;

returnStatement: RETURN expression?;
printStatement: PRINT LPAREN expression RPAREN;

expression:
      primaryExpression
    | LPAREN expression RPAREN
    | expression LBRACK expression RBRACK
    | UNAROP expression
    | expression BINOP expression
    | expression COMPOP expression
    | expression LOGICOP expression
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
PRINT: 'print';
FOR: 'for';
WHILE: 'while';
IF: 'if';
ELSE: 'else';
STRUCT: 'struct';

BOOL: 'true' | 'false';
INT: [0-9]+;
DOUBLE: [0-9]+ DOT [0-9]*;
CHAR: '\'' . '\'';
ID: [a-zA-Z_][a-zA-Z_0-9]*;

BINOP: '+' | '-' | '/' | '*';
UNAROP: '!' | '-';
COMPOP: '==' | '!=' | '<' | '>' | '<=' | '>=';
LOGICOP: '&&' | '||';
ASSIGN: '=';
LPAREN: '(';
RPAREN: ')';
LBRACE: '{';
RBRACE: '}';
LBRACK: '[';
RBRACK: ']';
SEMI: ';';
COMMA: ',';
DOT: '.';

WS: [ \t\r\n]+ -> skip;
COMMENT: '//' ~[\r\n]* -> skip;