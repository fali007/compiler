%{
	#include <stdio.h>
	#include "y.tab.h"
	#include <stdlib.h>
	#include "exprtree.h"
	int number;

%}

%%

[0-9]+	{number = atoi(yytext);yylval.no = createTree(number,0,NULL,CONSTANT,NULL,NULL); return NUM;}
"begin" {return PBEGIN;}
"end" 	{return PEND;}
"read"	{return PREAD;}
"write"	{return	PWRITE;}
[a-z]   {yylval.no=createTree(0,0,*yytext,VAR,NULL,NULL); return ID; }
";"		{return *yytext;}
"="		{return *yytext;}
"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MUL;}
"/"		{return DIV;}
[ \t]	{}
[()]	{return *yytext;}
[\n]	{}
.		{yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
	return 1;
}
