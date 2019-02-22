
%{

#include<stdio.h>
#include<stdlib.h>
%}

%token LETTER

%%

/*** Rules Section ***/
variable : character	{printf("\n\t if{);}
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

yylex(){
    char c;
    c = getchar();
    if(isdigit(c)){
        pos++;
        return DIGIT;
    }
    else if(isalpha(c)){
        pos++;
        return LETTER;         
    }
}

int main()
{
	yyparse();
	return 1;
}