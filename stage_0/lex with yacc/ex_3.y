%{
  #include <stdio.h>
  int yyerror();
  char *temp;
  extern char *yytext;
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

expr: expr '+' expr		{printf("+ %s",temp);}
    | expr '*' expr		
	| '(' expr ')'
    | LETTER            {temp=(char*)malloc(10*sizeof(char));temp=strdup(yylval.str);}
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