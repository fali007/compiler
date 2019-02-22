%{

#include<stdio.h>
#include<stdlib.h>
%}

%token LETTER

%%

/*** Rules Section ***/
variable : LETTER	{printf(" ");}
      ;

character: 
    | LETTER
    ;
%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}

int main()
{
	yyparse();
	return 1;
}