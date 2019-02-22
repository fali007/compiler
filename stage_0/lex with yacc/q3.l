
%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
    #include "y.tab.h"
%}


%%
 
[a-zA-Z] {return LETTER;}

%%
 