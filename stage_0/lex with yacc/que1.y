%{
#include<stdio.h>
#include<stdlib.h>
int count=0;
%}

%token IF OP NUM ID NL

%%
start: if_stmt NL {count++;printf("No. of nested if statements=%d\n",count);exit(0);}
;
if_stmt : IF'('cond')''{'if_stmt'}'    {count++;}  
         |IF'('cond')' '{''}'       
; 
        
cond: x OP x  {printf("condition reached\n");}
;
x:ID | NUM
;
%%

int main()
{
printf("enter the if statement\n");
yyparse();
return 1;
}
int yyerror(char *msg)
{
printf("the statement is invalid\n");
exit(0);
}
