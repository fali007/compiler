%{
	#include <stdio.h>
	#include "y.tab.h"
	#include <stdlib.h>
	#include "exprtree.h"
	int number;

%}

%%

[0-9]+			{number = atoi(yytext);yylval.no = createTree(number,INTEGER,NULL,NODE_CONSTANT,NULL,NULL,NULL); return NUM;}
"begin" 		{return PBEGIN;}
"end" 			{return PEND;}
"read"			{return READ;}
"write"			{return	WRITE;}
"if"			{return IF;} //conditional constructs
"then"			{return then;}
"else"			{return Else;}
"endif" 		{return ENDIF;}
"breakpoint" 	{return BRKP; }
"break" 		{return BREAK_L;}
"continue" 		{return CONTINUE_L;}
"while" 		{return WHILE;}
"do"			{return DO;}
"endwhile" 		{return ENDWHILE;}
"until" 		{return UNTIL;}
"repeat" 		{return REPEAT;}
[a-z]   		{yylval.no=createTree(0,INTEGER,*yytext,NODE_VAR,NULL,NULL,NULL); return ID; }
";"				{return *yytext;}
"="				{return *yytext;}
"+"				{return PLUS;}
"-"				{return MINUS;}
"*"				{return MUL;}
"/"				{return DIV;}
"<"				{return LT;} // boolean constucts
"<="			{return LE;}
">"				{return GT;}
">="			{return GE;}
"=="			{return EQ;}
"!=" 			{return NE;}
[ \t]			{}
[()]			{return *yytext;}
[\n]			{}
.				{yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
	return 1;
}
