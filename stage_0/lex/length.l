%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
%}
number[0-9]+

%%
{number} printf("Number of digits = %zu",yyleng);
%%
int main(){
	yylex();
	return 1;
}