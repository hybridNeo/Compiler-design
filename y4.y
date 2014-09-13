%{
#include <stdio.h>
%}
%token a b c
%%
S : A B 
A : C a |
B : c A C |
C : b
|
;
%%
int yylex(){
	char ch;
	ch = getchar();
	if(ch =='a')
		return a;
	else if(ch == 'b')
		return b;
	else if(ch == 'c')
		return c;
	else if(ch == '\n')
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
