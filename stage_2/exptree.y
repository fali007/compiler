%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "exprtree.h"
	#include "exprtree.c"
	int yylex(void);
%}

%union{
	struct tnode *no;
	//char str;
}

%type <no> expr NUM program Slist Stmt InputStmt OutputStmt AsgStmt ID
%token NUM PLUS MINUS MUL DIV NEWLINE PBEGIN PREAD PWRITE  PEND ID
%left PLUS MINUS
%left MUL DIV

%%
program : PBEGIN Slist PEND';'      {$$=$2;codeGen($2);evaluate($2);}
	| PBEGIN PEND					{$$=NULL;}
	;

Slist : Slist Stmt 		{$$ = createTree(0,0,NULL,CONN,$1,$2);}
	| Stmt				{$$=$1;}
	;
	
Stmt : InputStmt 		{$$=$1;}
	| OutputStmt 		{$$=$1;}
	| AsgStmt			{$$=$1;}
	;

InputStmt : PREAD'('ID')'';'	{$$ = createTree(0,0,NULL,READ,$3,NULL);}
	;

OutputStmt : PWRITE'('expr')'';'	{$$ = createTree(0,0,NULL,WRITE,$3,NULL);}
	;
	
AsgStmt : ID'='expr';' 		{$$ = createTree(0,0,'=',ASSGN,$1,$3);}
	;	
	
expr : expr PLUS expr		{$$ = createTree(0,0,'+',EX,$1,$3);}
	 | expr MINUS expr  	{$$ = createTree(0,0,'-',EX,$1,$3);}
	 | expr MUL expr		{$$ = createTree(0,0,'*',EX,$1,$3);}
	 | expr DIV expr		{$$ = createTree(0,0,'/',EX,$1,$3);}
	 | '(' expr ')'			{$$ = $2;}
	 | NUM					{$$ = $1;}
	 | ID					{$$ = $1;}
	 ;

%%

int yyerror(char const *s)
{
    printf("yyerror %s",s);
	return 0;
}


int main(int argc,char* argv[]) {
if(argc > 1)
	{
		FILE *fp = fopen(argv[1], "r");
		if(fp)
			yyin = fp;
}
 	xsm_fl=fopen("comp.xsm","w");
	fprintf(xsm_fl, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n ",0,2056,0,0,0,0,0,0); 
	fprintf(xsm_fl, "BRKP\n");
	fprintf(xsm_fl, "MOV SP, 4121\n");
	yyparse();
	return 0;
}