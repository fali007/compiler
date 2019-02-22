%{

#include<stdio.h>
#include<stdlib.h>
%}

%token LETTER DIGIT

%%

/*** Rules Section ***/
variable : LETTER DIGIT	{printf("ACCEPTABLE");}
      ;

character: 
    | LETTER
    | DIGIT
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