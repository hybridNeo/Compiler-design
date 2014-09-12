%{
	#include <stdio.h>

%}
%%
"//".* ;
"/*"(.*\n)*.*"*/" ;
%%

int yywrap(){
	return 1;
}
int main(){
 extern FILE* yyin;
 yyin=fopen("test.c","r");
 //FILE* yyout;
 yyout = fopen("fixedtest.c","w");  
 yylex();

}
