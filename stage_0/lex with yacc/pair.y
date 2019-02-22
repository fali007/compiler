%{
  #include <stdio.h>
  int yyerror();
%}

%token DIGIT NEWLINE

%%

start : pair 		{printf("\nComplete"); }
	;

pair: num','num{ printf("pair(%d,%d)",$1,$2); }
  ;
num: DIGIT			{ $$=$1; }
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