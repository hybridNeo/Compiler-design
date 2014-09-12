%{
	#include <stdio.h>
%}
%%
if|else|for|int|while|double|float|break|switch|return	{printf("%s It is a keyword\n",yytext);}
[_a-zA-Z]+[a-zA-Z0-9]*	{printf("%s It is an identifier\n",yytext);}

%%
int yywrap(){
	return 1;
}
int main(){
	extern FILE* yyin;
	yyin = fopen("test.txt","r");
	yylex();
return 0;
}
