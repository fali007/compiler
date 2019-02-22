%option noyywrap
%{
	#include <stdlib.h>
	#include <stdio.h>
	FILE *out;
	char *prev;
%}
	
pattern [A-Za-z]+

%%
 
{pattern} {if(strcmp(prev,yytext)!=0) fprintf(out,"%s " ,yytext);
			printf("%d ",strcmp(prev,yytext));
			prev=strdup(yytext);}
 
%%
 
int main() {
	char a[10]="asd";
  	yyin = fopen("input_file.txt","r");
  	out=fopen("output_file.txt","w");
	// prev=(char*)malloc(10*sizeof(char));
	// prev=a;   
    yylex();
    return 1;
}   