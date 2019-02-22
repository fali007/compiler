%{
  #include <stdio.h>
  int yyerror();

%}

%union
{
	char *str;

};

%token DIGIT NEWLINE LETTER
%type <str> LETTER
%left '+'
%left '*'

%%

start : expr  NEWLINE   {printf("\nComplete");exit(1); }
	;

expr: expr '+' expr		{printf("+");}
    | expr '*' expr		{printf("*");}
	  | '(' expr ')'
    | LETTER            {printf("%s ",$1);}
	;

%%

int yyerror()
{
	printf("Error");
}

int main()
{
  yyparse();
  return 1;
}