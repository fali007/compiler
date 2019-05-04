%{
	#define YYSTYPE struct tnode*
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "tree.h"
	#include "y.tab.h"
	YYSTYPE yylval;
	
%}
%option noyywrap

%%
"read"   	                {return READ;}
"write"   	                {return WRITE;}
"begin"                     {return BEG;}
"end"                       {return END;}
[=]                         {return ASGN;}
[ \t\n] 	                {}
"-"                         {return MINUS;}
"+"                         {return PLUS;}
"*"                         {return MUL;}
"/"  	                    {return DIV;}
"%"                         {return MOD;}
"<" 		                {return LT;}
">"                         {return GT;}
"<=" 	                	{return LE;}
">="                        {return GE;}
"=="                        {return EQ;}
"!="                        {return NEQ;}
"AND"                       {return AND;}
"OR"                        {return OR;}
"NOT"                       {return NOT;}
"if" 		                {return IF;}
"then" 		                {return THEN;}
"while" 	                {return WHILE;}
"endwhile"               	{return ENDWHILE;}
"endif" 	                {return ENDIF;}
"do" 		                {return DO;}
"else"                      {return ELSE;}
"break"                     {return BREAK;}
"continue"                  {return CONTINUE;}
"repeat"                    {return REPEAT;}
"until"                     {return UNTIL;}
"decl"                      {return DECL;}
"enddecl"                   {return ENDDECL;}
"int"                       {return INT;}
"str"                       {return STR;}
"main"                      {return MAIN;}
"return"                    {return RETURN;}
"["                         {return *yytext;}
"]"	                        {return *yytext;}
[();,{}]    	            {return *yytext;}
[0-9]+                   	{yylval = Createtree(atoi(yytext),INTTYPE,NULL,NUM,NULL,NULL,NULL);return NUM;}
[a-zA-Z][a-zA-Z0-9]*	    {yylval = Createtree(0,0,strdup(yytext),ID,NULL,NULL,NULL);return ID;}
.                           { printf("Error in lex %s   " ,yytext);exit(1);}
%%
