%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
    
%}

words [a-zA-Z]+	

%%

{words} {if(yyleng==3)printf("%s",yytext);}

%%
 
int main()
{
	yylex();
	return 1;
}