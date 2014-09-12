%{
	#include<stdio.h>
	int vowels = 0;
	int consonents = 0;
%}
%%
[aeiou]	{vowels++;}
[a-z]	{consonents++;}
.*;
%%
int yywrap(){
	return 1;
}
int main(){
	extern FILE* yyin;
	yyin = fopen("test.txt","r");
	yylex();
	printf("The number of vowels is %d",vowels);
	printf("The number of consonents is %d",consonents);

}
