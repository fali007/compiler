%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
    int words=0;
    int characters=0;
    int lines=1;
%}

word [a-zA-Z]+
character [a-zA-Z]
line [\n]
%%

{word} {++words;characters+=yyleng;}
{character} {++characters;}
{line} {++lines;++characters;}
 
%%
 
int main()
{
	yylex();
    printf("lines : %d \nwords : %d \ncharacters : %d \n",lines,words,characters);
	return 1;
}