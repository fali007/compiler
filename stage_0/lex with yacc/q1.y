%{

#include<stdio.h>
#include<stdlib.h>
%}

%token IF STMT

%%

/*** Rules Section ***/
variable : IF "(" STMT ")"  {printf("\n\tif(");}
      ;

character: 
    | IF
    | STMT
    | "("
    | ")"
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