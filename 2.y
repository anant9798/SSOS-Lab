%{
	#include <stdio.h>
	#include <stdlib.h>
	int n = 0;
%}
%token A B
%%
ans: T B
T: A T | A {;}
%%
main() {
	printf("Enter n value: \n");
	scanf("%d", &n);
	printf("Enter exp: ");
	yyparse();
	printf("Valid exp\n");
}
int yyerror() {
	printf("invalid\n");
	exit(0);
}