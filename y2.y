%{
#include <stdio.h>
%}
%token a b

%%
S : A S B |

A : a A |
B : b B |
;
%%
int yylex(){
	char ch;
	ch = getchar();
	if(ch =='a')
		return a;
	else if(ch == 'b')
		return b;
	else 
		return 0;	
}
int main()
{	
	if(!yyparse())printf("It is a valid String\n");


}
int yyerror(){
	printf("It is not valid \n");
	return 0;

}

