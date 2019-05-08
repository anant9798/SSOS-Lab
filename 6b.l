%{
#include <stdio.h>
#include "y.tab.h"
%}
%%
"#".*	{}
[" "|\t]	;
[\+|\-|\*|\/|=|<|>]	{printf("\nOP: ");ECHO;return OP;}
"int"|"char"|"bool"|"float"|"void"|"for"|"do"|"while"|"if"|"else"|"return"	{printf("\nKW: ");ECHO;return KEY;}
[a-z|A-Z|_][a-z|A-Z|_|0-9]*[(|)|;]?	{printf("\nID: ");ECHO;return ID;}
[0-9]+	{printf("\nDIG: ");ECHO;return DIG;}
.	;
%%
