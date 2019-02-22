%{
  #include <stdio.h>
  int yyerror();
  #define  YYSTYPE char

%}

%token DIGIT NEWLINE LETTER

%left '+'
%left '*'

%%

start : expr  NEWLINE   {printf("\nComplete"); }
	;

expr: expr '+' expr		{printf("+");}
    | expr '*' expr		{printf("*");}
	  | '(' expr ')'
	  | DIGIT	          {printf("%d ",$1);}
    | LETTER          {printf("%c ",$1);}
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