%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
    #include "tree.h"
	char *removequotes();
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
"["                         {return *yytext;}
"]"	                        {return *yytext;}
[();,]    	                {return *yytext;}
[0-9]+                   	{yylval.no = Createtree(atoi(yytext),INTTYPE,NULL,NUM,NULL,NULL,NULL,NULL);return NUM;}
\"(.)*\"                    {yylval.no = Createtree(0,STRTYPE,strdup(removequotes()),STRING,NULL,NULL,NULL,NULL); return STRING;}
[a-zA-Z][a-zA-Z0-9]*	    {yylval.no = Createtree(0,0,strdup(yytext),ID,NULL,NULL,NULL,NULL);return ID;}
.                           { printf("Error in lex %s   " ,yytext);exit(1);}
%%

char* removequotes()
{
    yytext[yyleng-1]='\0';
    return yytext+1; 

}