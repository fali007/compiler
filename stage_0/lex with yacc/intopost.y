%{
      #include <stdio.h>
%}

%token DIGIT NEWLINE
 
%%

start : expr NEWLINE  {
                        printf("\nComplete\n");
                        exit(1);
                      }
  ;

expr:  expr '+' expr        {printf("+ ");}
  | expr '-' expr     {printf("- ");}
  | '(' expr ')'
  | DIGIT             {printf("%d ",$1);}
  ;

%%

yyerror(char const *s)
{
    printf("yyerror  %s\n",s);
    return 1;
}
int main()
{
  yyparse();
  return 1;
}