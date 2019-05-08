%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
%}
%%
"//".*  {}
"/*"([^\*\/])*"*/"   {}
%%
int main(int argc, char** argv)
{
    if(argc!=3){
        printf("Usage: ./a.out infile outfile\n");
        exit(0);
    }
    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2], "w");
    yylex();
}