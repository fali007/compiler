%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
	int i;
%}
	
number [0-9]+
%%
 
{number} {i=atoi(yytext);printf("Found : %d\n",i); if(i%2==0) printf("Even !"); else printf("Odd !");};
 
%%
 
int main()
{
	yylex();
	return 1;
}