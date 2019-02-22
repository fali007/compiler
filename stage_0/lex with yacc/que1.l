
%{
#include "y.tab.h"
%}
%option noyywrap
%%
"if" {return IF;}
"<"|">"|"=="|"<="|">="|"!=" {return OP;}
"("|")"|"="|"{"|"}"    {return *yytext;}
[0-9]+ {return NUM;}
[a-z][a-zA-Z0-9_]* {return ID;}
\n {return NL;}
. {return yytext[0];}
%%

