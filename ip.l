%{
 #include <stdio.h>
%}

d1 1?[0-9]?[0-9]
d2 {d1}|2[0-4][0-9]|25[0-5]
ip {d2}"."{d2}"."{d2}"."{d2} 
%%
{ip}	{printf("It is a valid ip ");}

%%
int yywrap(){
	return 1;
}
int main(){
	yylex();
	return 0;
}
