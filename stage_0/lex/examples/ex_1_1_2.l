%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
    int integer=0;
    int flot=0;
%}

integers [0-9]+	
floats [0-9]+\.[0-9]+

%%

{floats} {++flot;}
{integers} {++integer;}

%%
 
int main()
{
	yylex();
    printf("integer : %d \nfloat : %d \n",integer,flot);
	return 1;
}