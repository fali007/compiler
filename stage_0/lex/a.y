%{

#include<stdio.h>
#include<stdlib.h>
FILE *yyin;
FILE *out;
extern char *yytext;


%}

%token CHAR SPACE

%%

/*** Rules Section ***/
word : character  {fprintf(out,"%s",yytext);}
      ;

character: 
    | CHAR
    | SPACE
    ;
%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}

int main() {
    yyin = fopen("input_file.txt","r");
  	out=fopen("output_file.txt","w");
    yyparse();
    return 1;
} 