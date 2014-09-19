%{
 #include <stdio.h>
%}
%token A B
%%
S : B T
T : A T |
%%

int main(){
	if(!yyparse()) printf("Valid string ... \n"); 
}

int yyerror(){
	printf("Does not satisfy grammar");
	return 0;
}
