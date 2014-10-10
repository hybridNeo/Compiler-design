%{
 #include "y.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9]*   {return ID;}
[0-9]+   {return NUM;}
[+]  {return PLUS;}
[-]  {return MINUS;}
[*]  {return MUL;}
[/]  {return DIV;}
%%




