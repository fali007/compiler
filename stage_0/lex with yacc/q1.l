
%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
    #include "y.tab.h"
	int i;
%}


%%
 
[a-zA-Z0-9=!] {return STMT;}
"if" {return IF;}
[(){}] {return *yytext;}
(.) {printf("invalid entry");}

%%
 