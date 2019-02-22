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

%type <no> expr NUM program Slist Stmt 
%type <no> InputStmt OutputStmt AsgStmt
%type <no>  ID Ifstmt Whilestmt DoWhileStmt Repeatstmt
%type <no> CONTINUE_L BRKP BREAK_L sp_comm
%token NUM PLUS MINUS MUL DIV NEWLINE 
%token PBEGIN READ WRITE  PEND ID 
%token IF then Else ENDIF WHILE DO ENDWHILE REPEAT UNTIL
%token GT GE LT LE EQ NE
%token CONTINUE_L BRKP BREAK_L  
%left GT GE LT LE EQ NE
%left PLUS MINUS
%left MUL DIV

%%
program : PBEGIN Slist PEND      						{$$=$2;codeGen($2);inorder($2);}
	| PBEGIN PEND										{$$=NULL;}
	;

Ifstmt :IF '('expr')' then Slist Else Slist ENDIF ';'	{$$=createTree(0,0,NULL,NODE_IF,$3,$6,$8);}
	| IF '('expr')' then Slist ENDIF';'					{$$=createTree(0,0,NULL,NODE_IF,$3,$6,NULL);}
	;				

Whilestmt : WHILE '('expr')' DO Slist ENDWHILE';'		{$$=createTree(0,0,NULL,NODE_WHILE,$3,NULL,$6);}
	;

DoWhileStmt:DO Slist WHILE'('expr')'';'					{$$=createTree(0,0,NULL,NODE_DOWHILE,$2,NULL,$5);}
	;		

Repeatstmt:UNTIL Slist REPEAT'('expr')'';'				{$$=createTree(0,0,NULL,NODE_REPEAT,$2,NULL,$5);}
	;		

Slist : Slist Stmt 										{$$=createTree(0,0,NULL,NODE_CONN,$1,NULL,$2);}
	| Stmt												{$$=$1;}
	;
	
Stmt : InputStmt 										{$$=$1;}
	| OutputStmt 										{$$=$1;}
	| AsgStmt											{$$=$1;}
	| Ifstmt											{$$=$1;}
	| Whilestmt											{$$=$1;}
	| DoWhileStmt										{$$=$1;}
	| Repeatstmt										{$$=$1;}
	| sp_comm 											{$$=$1;}
	;
	

InputStmt : READ'('ID')'';'								{$$ = createTree(0,0,NULL,NODE_READ,$3,NULL,NULL);}
	;

OutputStmt : WRITE'('expr')'';'							{$$ = createTree(0,0,NULL,NODE_WRITE,$3,NULL,NULL);}
	;
	
AsgStmt : ID'='expr';' 									{$$ = createTree(0,0,'=',NODE_ASSGN,$1,NULL,$3);}
	;	

sp_comm : BRKP';' 										{$$=createTree(0,0,NULL,N_BRKP,NULL,NULL,NULL);}
	   | BREAK_L ';'									{$$=createTree(0,0,NULL,N_BREAK,NULL,NULL,NULL);}
	   | CONTINUE_L ';'									{$$=createTree(0,0,NULL,N_CONTINUE,NULL,NULL,NULL);}
	   ;	

expr : expr PLUS expr									{$$ = createTree(0,INTEGER,'+',NODE_EX,$1,NULL,$3);}
	 | expr MINUS expr  								{$$ = createTree(0,INTEGER,'-',NODE_EX,$1,NULL,$3);}
	 | expr MUL expr									{$$ = createTree(0,INTEGER,'*',NODE_EX,$1,NULL,$3);}
	 | expr DIV expr									{$$ = createTree(0,INTEGER,'/',NODE_EX,$1,NULL,$3);}
	 | '(' expr ')'										{$$ = $2;}
	 | expr GT expr										{$$ = createTree(0,BOOLE,NULL,N_GT,$1,NULL,$3);}		
	 | expr GE expr										{$$ = createTree(0,BOOLE,NULL,N_GE,$1,NULL,$3);}
	 | expr LT expr										{$$ = createTree(0,BOOLE,NULL,N_LT,$1,NULL,$3);}
	 | expr LE expr										{$$ = createTree(0,BOOLE,NULL,N_LE,$1,NULL,$3);}
	 | expr EQ expr										{$$ = createTree(0,BOOLE,NULL,N_EQ,$1,NULL,$3);}
	 | expr NE expr										{$$ = createTree(0,BOOLE,NULL,N_NE,$1,NULL,$3);}
	 | NUM												{$$ = $1;}
	 | ID												{$$ = $1;}
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
 xsm_file=fopen("arith.xsm","w");
	header_printer();
	yyparse();
	answer_storer();
	return 0;
}								