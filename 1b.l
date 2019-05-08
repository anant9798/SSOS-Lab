%{
  #include "y.tab.h"
  extern yylval;
%}
%%
[0-9]+	{yylval = atoi(yytext); return NUM;}
\+	{return PLUS;}
\-	{return MINUS;}
\*	{return MUL;}
\/	{return DIV;}
[)]	{return yytext[0];}
[(]	{return yytext[0];} 
.	{;}
\n	{return NL;}
%%