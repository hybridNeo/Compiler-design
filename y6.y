%{
	#include <stdio.h>
	#include <ctype.h>
	#include <stdlib.h>
%}
%token num let
%left '+' '-'
%left '*' '/'

%%
Statement:	Statement '\n'	{printf("Vaild expression\n");
exit(0);}
| expr
|
| error '\n'	{printf("It is invalid\n");exit(0);}
expr:	num
|let
|expr '+' expr
|expr '-' expr
|expr '*' expr
|expr '/' expr
|'(' expr ')' 
%%
int yylex(){
	int ch;
	ch = getchar();
	if(isdigit(ch))
		return num;
	if(isalpha(ch))
		return let;
	return ch;

}
int yyerror(char *s){
	printf("%s",s);
}
int main(){

	yyparse();
}
