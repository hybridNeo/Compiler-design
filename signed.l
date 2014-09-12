%{
	#include <stdio.h>
%}
number [0-9]+
digits {number}"."{number}
fractional {number}.["."{number}]?E[+|-][digit]


%%
{number}|{digits}	{printf("It is a unsigned number\n");}
.*	{printf("It is an signed number\n");}
%%
int yywrap(){
	return 1;
}
int main(){
yylex();
return 1;
}
