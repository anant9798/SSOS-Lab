%{
    #include <stdio.h>
    #include <stdlib.h>
    int id = 0, op = 0, flag=0;
%}
%%
[0-9]+  {printf("\nIdentifier: "); ECHO; id++;}
[\+|\-|\*|\/|=] {op++; printf("\nOperator: "); ECHO;}
[.|\n]  {;}
";" {flag =1;}
%%
int main()
{
    printf("Enter expression: \n");
    yylex();
    if((op+1)==id && flag == 0){
        printf("\nNo. of Identifiers: %d\n", id);
        printf("No. of Operators: %d\n", op);
        printf("Valid Expression\n");
    }
    else{
        printf("\nInvalid Exp\n");
    }
}