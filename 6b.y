%{
 #include <stdio.h>
 #include <stdlib.h>
 int k=0,i=0,op=0,dig=0;
%}
%token ID OP KEY DIG
%%
input:	ID input	{i++;}
|OP input	{op++;}
|KEY input {k++;}
|DIG input	{dig++;}
|ID	{i++;}
|OP	{op++;}
|KEY	{k++;}
|DIG	{dig++;}
;
%%
extern int yylex();
extern FILE* yyin;
void main(int argc, char ** argv)
 {
  yyin = fopen(argv[1],"r");
  yyparse();
  printf("\nIdentifiers: %d \nKey words: %d \nOperators: %d\nDIG: %d\n",i,k,op,dig);
 }
 int yyerror()
 {
  printf("ERRROOORRR");
  exit(0);
 } 
  
 
