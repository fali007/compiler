%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "tree.h"
	#include "tree.c"
	#include "symbol.h"
	#include "symbol.c"
	#include "codegen.h"
	#include "codegen.c"
    struct tnode *root = NULL;
%}

%union
{
 struct tnode *no;
}
%type <no> exp NUM ID slist stmt start DeclBlock DeclList Declaration Type VariableList Variable STRING
%token NUM PLUS MINUS MUL DIV BEG READ WRITE END ASGN ID LT GT LE GE EQ NEQ IF THEN WHILE ENDWHILE ENDIF DO ELSE REPEAT UNTIL BREAK CONTINUE
%token DECL ENDDECL INT STR STRING CONN INTTYPE STRTYPE BOOLTYPE MOD
%right ASGN
%left PLUS MINUS
%left MUL DIV MOD
%nonassoc LT GT LE GE EQ NEQ

%%

start: DeclBlock BEG slist END';' { root = $3;}
     | BEG END                    {exit(0);} 
;

DeclBlock: DECL DeclList ENDDECL  {printtable();$$ = $2;}
         | DECL ENDDECL           {$$ = NULL;}
;

DeclList: Declaration
        | DeclList Declaration
;

Declaration: Type VariableList ';'          {varinstall($1->type,$2);}
;

Type: INT                                   {$$ = Createtree(0,INTTYPE,NULL,0,NULL,NULL,NULL,NULL);}
    | STR                                   {$$ = Createtree(0,STRTYPE,NULL,0,NULL,NULL,NULL,NULL);}
;

VariableList: Variable
            | VariableList ',' Variable     {$$ = Createtree(0,0,NULL,CONN,NULL,$1,$3,NULL);}
;

Variable: ID                      {$1->intVal = 1; $$ = $1;} 
         | ID'['NUM']'            {$1->intVal = $3->intVal; $$ = $1;}
		 | ID '['NUM']''['NUM']'  { struct tnode *row = malloc(sizeof(struct tnode));
                                    struct tnode *column = malloc(sizeof(struct tnode));
									row=Createtree($3->intVal,0,NULL,NUM,NULL,NULL,NULL,NULL);
									column=Createtree($6->intVal,0,NULL,NUM,NULL,NULL,NULL,NULL);
                                    $1->intVal = $3->intVal*$6->intVal;
									$1->left=row;$1->right=column;$$=$1;}
;
slist: slist stmt             {$$=Createtree(0,0,NULL,CONN,NULL,$1,$2,NULL);}   
     | stmt                   {$$=$1;}
;
exp:   NUM                     
     | STRING                 {$$=$1;}
     | ID                     {$1->varNode = Lookup($1->stringVal); if($1->varNode == NULL) {printf("Undeclared Variable\n"); exit(1);} $$ = $1;}
	 | ID'['exp']'            {$$ = Createtree(0,0,$1->stringVal,ID,Lookup($1->stringVal),$3,NULL,NULL);}
	 | ID'['exp']''['exp']'   {$$ = Createtree(0,0,$1->stringVal,ID,Lookup($1->stringVal),$3,$6,NULL);}
     | exp PLUS exp		      {$$ = Createtree(0,INTTYPE,NULL,PLUS,NULL,$1,$3,NULL);}
	 | exp MINUS exp          {$$ = Createtree(0,INTTYPE,NULL,MINUS,NULL,$1,$3,NULL);}
	 | exp MUL exp	          {$$ = Createtree(0,INTTYPE,NULL,MUL,NULL,$1,$3,NULL);}
	 | exp DIV exp	          {$$ = Createtree(0,INTTYPE,NULL,DIV,NULL,$1,$3,NULL);}
	 | exp MOD exp		      {$$ = Createtree(0,INTTYPE,NULL,MOD,NULL,$1,$3,NULL);}
	 | exp LT exp	          {$$ = Createtree(0,BOOLTYPE,NULL,LT,NULL,$1,$3,NULL);}
     | exp GT exp	          {$$ = Createtree(0,BOOLTYPE,NULL,GT,NULL,$1,$3,NULL);}
     | exp LE exp	          {$$ = Createtree(0,BOOLTYPE,NULL,LE,NULL,$1,$3,NULL);}
	 | exp GE exp	          {$$ = Createtree(0,BOOLTYPE,NULL,GE,NULL,$1,$3,NULL);}
	 | exp EQ exp	          {$$ = Createtree(0,BOOLTYPE,NULL,EQ,NULL,$1,$3,NULL);}
	 | exp NEQ exp	          {$$ = Createtree(0,BOOLTYPE,NULL,NEQ,NULL,$1,$3,NULL);}
	 | '('exp')'		      {$$ = $2;}

;
	
stmt: exp ASGN exp';'                             {$$ = Createtree(0,0,'=',ASGN,NULL,$1,$3,NULL);}
    | READ '('exp')'';'                           {$$ = Createtree(0,0,NULL,READ,NULL,$3,NULL,NULL);}
	| WRITE '('exp')'';'                          {$$ = Createtree(0,0,NULL,WRITE,NULL,$3,NULL,NULL);}
	| IF '('exp')' THEN slist ELSE slist ENDIF';' {$$ = Createtree(0,0,NULL,IF,NULL,$3,$6,$8);}
	| IF '('exp')' THEN slist ENDIF';'            {$$ = Createtree(0,0,NULL,IF,NULL,$3,$6,NULL);}
	| WHILE '('exp')' DO slist ENDWHILE';'        {$$ = Createtree(0,0,NULL,WHILE,NULL,$3,$6,NULL);}
	| DO slist WHILE '('exp')'';'                 {$$ = Createtree(0,0,NULL,DO,NULL,$5,$2,NULL);}
	| REPEAT slist UNTIL '('exp')'';'             {$$ = Createtree(0,0,NULL,REPEAT,NULL,$5,$2,NULL);}
	| BREAK';'                                    {$$ = Createtree(0,0,NULL,BREAK,NULL,NULL,NULL,NULL);}
    | CONTINUE';'                                 {$$ = Createtree(0,0,NULL,CONTINUE,NULL,NULL,NULL,NULL);}
;
%%

yyerror(char *s)
{
    printf("error in yacc %s",s);
	exit(0);
}

int main(int argc,char* argv[]) {
if(argc > 1)
	{
		FILE *fp = fopen(argv[1], "r");
		if(fp)
			yyin = fp;
}   
    out = fopen(argv[2],"w");
	yyparse();
	initialize();
	stack0();
	codegen(root);
	exit0();
    return 0;
}
