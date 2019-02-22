%{
    #include <stdio.h> 
	#include "y.tab.h"
	#include<stdlib.h>
	  
%}

%%
[a-z]+	{ 
        yylval.str=strdup(yytext);
        return LETTER;
        }
"+"	  return *yytext;
"-"	  return *yytext;
"*"	  return *yytext;
"/"	  return *yytext;
[()]  return *yytext;
[\n]  return NEWLINE;

%%

yywrap()
{
	return 1;
}
