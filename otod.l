%{
#include <stdio.h>
#include <math.h>
int k;
%}
%%
[0-7]*	{k = atoi(yytext);}

%%
int yywrap(){
	return 1;
}
int main(){
	yylex();
	int i=0;
	int decimal = 0;
	while(k!=0){
		decimal = decimal + (k%10) * pow(8,i++);
		k = k/10;
	}
	printf("Decimal is %d",decimal);
	return 0;
}
