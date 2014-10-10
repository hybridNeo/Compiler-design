%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int keywords=0, identifiers=0;
int addr;
install ( char *sym_name )
{  sym *s;
   s = getsym (sym_name);
   if (s == 0)
        s = putsym (sym_name);
   else { errors++;
          printf( "%s is already defined\n", sym_name );
   }
}
context_check( char *sym_name )
{ if ( getsym( sym_name ) == 0 ) 
     printf( "%s is an undeclared identifier\n", sym_name );
}
struct sym{
	int val;
	char *name;
	struct sym *next;
};
typedef struct sym sym;
sym *sym_table = (sym*)0;
sym *putsym();
sym *getsym();
void symCheck(char *a){
	if(getsym(a) == 0){
		printf("Not there in table adding\n");
		//putsym(a);	
	}else{
		printf("There");
	}
}
%}

%%
if|else|case|for|switch|break|int|float|char|double|long|do|while	{printf("Keyword: %s\n",yytext);}
[a-zA-Z][a-zA-Z0-9]*	{ context_check(yytext);}

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
sym* putsym(char *sym_name){
	sym *ptr;
	ptr = (sym*)malloc(sizeof(sym));
	ptr->name = (char*)malloc(sizeof(sym));
	ptr->next = (sym*)sym_table;
	sym_table = ptr;
	return ptr;
}
sym* getsym ( char *sym_name )
{
  sym *ptr;
  for (ptr = sym_table; ptr != (sym *) 0;
       ptr = (sym *)ptr->next);
    if (strcmp (ptr->name,sym_name) == 0)
      return ptr;
  return 0;
}
int yywrap()
{
return 1;
}

int main()
{
yylex();
return 0;
}

