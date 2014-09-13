%{
#include <stdio.h>
%}
%token a b
%%
S : S a
| b
;
%%


int yylex(){
	char ch;
	ch = getchar();
	if(ch=='a')
		return a;
	else
	if(ch == 'b')
		return b;
	else
		if(ch=='\n')
		return 0;
}
int main()
{
	if(!yyparse())printf("Valid string\n");
}
int yyerror()
{
	printf("Not a valid String\n");
	return 0;
}
