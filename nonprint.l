%{
#include <stdio.h>

%}
%%
.	{char c = yytext[0];printf("%d",c);}

%%
int yywrap(){
	return 1;
}
int main(){
	yylex();
	return 0;

}
