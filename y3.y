%{
#include <stdio.h>
%}
%token a b
%%
S : b T
T : a T
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
