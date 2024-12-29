grammar SimpleLanguage;

program: statement+;

statement: 'print' STRING ';';

STRING: '"' .*? '"';
WS: [ \t\r\n]+ -> skip;