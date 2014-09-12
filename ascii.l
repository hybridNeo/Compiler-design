%{
	#include <stdio.h>
%}
%%
["\n""\b""\t"" "]	{printf("%d\n",yytext[0]);}

%%
int yywrap(){
	return 1;
}
int main(){
	yylex();
}
