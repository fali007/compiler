%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>

	#define MINUS 1
	#define DECREMENT 2
%}



%%

“-”  {return MINUS;}
“--” {return DECREMENT;}

%%
int main(){
	int a=yylex();
	if(a==MINUS)
		printf("MINUS\n");
	else if(a==DECREMENT)
		printf("DECREMENT\n");
	return 1;
}
