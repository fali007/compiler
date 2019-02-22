
%{

#include<stdio.h>
#include<stdlib.h>
int pos=0;

%}

%token DIGIT LETTER

%%

/*** Rules Section ***/
variable : LETTER character		{printf("acceptable");}
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