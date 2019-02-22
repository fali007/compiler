
%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
    #include "y.tab.h"
	int i;
%}


%%
 
[A-Z] {return LETTER;}
[a-zA-Z0-9] {return DIGIT;}

%%
 