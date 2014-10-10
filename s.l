%{
#include<stdio.h>
#include<string.h>
int keywords=0, identifiers=0;
int addr;
typedef struct symbol{
	int val;
	char name[];
	struct symbol *next;
}
void symcheck(){
	print("Hello");
}
%}

%%
if|else|case|for|switch|break|int|float|char|double|long|do|while       

[a-zA-Z][a-zA-Z0-9]*  { hello();}

"+"|"-"|"*"|"/" {printf("arithmatic operator:%s\n",yytext);}
"=="|"<"|">"|"<="|">=" {printf("comparision operator: %s \n",yytext);}

"=" {printf("assignment operator:%s \n",yytext);}

"{" {printf("left braces: %s \n",yytext);}
"}" {printf("right braces: %s\n",yytext);}
"(" {printf("left paranthesis: %s \n",yytext);}
")" {printf("right paranthesis: %s\n",yytext);}
"!" {printf("not operator: %s\n",yytext);}
"^" {printf("power operator: %s \n",yytext);}
"&" {printf("logical AND: %s \n",yytext);}
"|" {printf("logical OR: %s \n",yytext);}
[0-9]+ {printf("digit : %s \n",yytext);}


.;

%%

int yywrap()
{
return 1;
}

int main()
{
yylex();
return 0;
}

