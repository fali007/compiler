%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>

%}

start [/*]

%%

{start} {printf("%s",yytext);}

%%
 
int main()
{
	yylex();
	return 1;
}