%{
  #include <stdio.h>
  int ident=0;
  int op=0;
  int flag=0;
%}
%%
[0-9]+	{ident++; printf("\nIdentifier: "); ECHO;}
[\+|\-|\*|/|=]	{op++; printf("\nOperator: "); ECHO;}
[.|\n]	{;}
";"	{flag=1;} 
%%
main()
{
  printf("Enter exp: \n");
  yylex();
  if((op+1)==ident && flag==0){
    printf("\nIdentifiers: %d\n",ident);
    printf("Operators: %d\n",op);
    printf("Valid Expression\n");
  }
  else
  {
    printf("\nInvaid\n");
  }
}