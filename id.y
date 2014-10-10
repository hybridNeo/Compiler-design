%{
#include<stdio.h>
%}

%token ID NUM PLUS MINUS MUL DIV 
%left '+' '-'
%left '*' '/'

%%
E: E PLUS E |
   E MINUS E |
   E MUL E |
   E DIV E | ID | NUM
   ;
%%


int main()
{
 if(!yyparse()) printf("Valid string....\n");
}

int yyerror()
{
 printf("Does not satisfies grammer\n");
 return 0;
}
