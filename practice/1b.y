%{
    #include <stdio.h>
    #include <stdlib.h>
%}
%token NUM PLUS MINUS MUL DIV NL
%left PLUS MINUS 
%left MUL DIV
%%
input: exp  {printf("%d\n", $$); exit(0);}
exp : exp PLUS exp  {$$ = $1+$3;}
exp : exp MINUS exp  {$$ = $1-$3;}
exp : exp MUL exp  {$$ = $1*$3;}
exp : exp DIV exp  {if($3 == 0) {printf("Div by 0 err\n"); exit(0);} else $$ = $1/$3;}
exp : NUM    {$$ = $1;}
exp : '('exp')' {$$ = $2;}
%%
int yyerror()
{
    printf("Error\n");
    exit(0);
}
int main()
{
    printf("Enter exp: \n");
    yyparse();
}