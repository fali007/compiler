%{  
    #define YYSTYPE struct tnode*
	#include <stdio.h>
	#include <stdlib.h>
    #include <string.h>
    #include "symbol.h"
    #include "symbol.c"
    #include "parameter.h"
    #include "parameter.c"
    #include "tree.h"
    #include "tree.c"
    #include "codegen.h"
    #include "codegen.c"

;
%}

%token NUM BEG READ WRITE END ASGN ID IF THEN WHILE ENDWHILE ENDIF DO ELSE REPEAT UNTIL BREAK CONTINUE MAIN 
%token DECL ENDDECL INT STR CONN INTTYPE STRTYPE BOOLTYPE VARIABLE ARRAY FUNCTION RETURN
%right ASGN
%left AND OR NOT
%left PLUS MINUS
%left MUL DIV MOD
%nonassoc LT GT LE GE EQ NEQ

%%

start: Gdeclblock Fdefblock Mainblock
     | Gdeclblock Mainblock
     | Mainblock
;

Gdeclblock: DECL Gdecllist ENDDECL  {Gprinttable();initialize();}
          | DECL ENDDECL          
;

Gdecllist: Gdecl
         | Gdecllist Gdecl
;

Gdecl: Type {dectype=ctype;} Glist ';'          
;

Type: INT                    {ctype=INTTYPE;}
    | STR                    {ctype=STRTYPE;}
;

Glist:  Glist ',' Gid 
    | Gid
;


Gid:  ID                      {Ginstall($1->stringVal,dectype,1,VARIABLE,NULL);} 
    | ID '[' NUM ']'          {if($3->intVal<=0) {printf("array %s size invalid ",$1->stringVal);exit(1);}
		                      Ginstall($1->stringVal,dectype,$3->intVal,ARRAY,NULL);}
    | ID '(' Paralist ')'     {Ginstall($1->stringVal,dectype,-1,FUNCTION,parahead);parahead=NULL;}
;

Paralist:
        | Paralist ',' para
        | para
;


para: Type ID                 { Parainstall($2->stringVal,ctype); }
;

Fdefblock:Fdefblock Fdef
         | Fdef
;

Fdef: Type ID               {dectype=ctype;}
      '('Paralist')'        {struct Gsymbol *temp=GLookup($2->stringVal);
                            if(temp== NULL){printf("function %s not defined ",$2->stringVal);exit(1);}
                            if(temp->type != dectype){printf("fun %s invalid return type",$2->stringVal);exit(1);}
                            checkpara(parahead,temp->paralist);Lparainstall();parahead=NULL;
                             fprintf(out,"F%d: ",temp->flabel);}
    '{'Ldeclblock Body '}'  {Lprinttable();fungen($10);
                             struct Gsymbol *temp = GLookup($2->stringVal);
                             if(temp->size == 0) {printf("multiple function declaration");exit(1);}
                             temp->size=0;Lsymboltable=NULL;}
;

Ldeclblock:
          | DECL ENDDECL
          | DECL Ldecllist ENDDECL
;

Ldecllist: LDecl
         | Ldecllist LDecl
;

LDecl: Type Llist ';'
;

Llist: ID                            {Linstall($1->stringVal,ctype);}
       | Llist ',' ID                {Linstall($3->stringVal,ctype);}
;

Body: BEG Slist Rstmt END           {$$ = Createtree(0,0,NULL,CONN,$2,$3,NULL);}
    | BEG Rstmt END                 {$$ = $2;}
;

Mainblock:INT MAIN '(' ')'          { dectype=INTTYPE;fprintf(out,"MAIN: ");}

         '{'Ldeclblock Body '}'     {Lprinttable();fungen($8);Lsymboltable=NULL;}

;

Rstmt:RETURN exp';'           {$$=Createtree(0,0,NULL,RETURN,$2,NULL,NULL);}
;

Slist: Slist stmt             {$$=Createtree(0,0,NULL,CONN,$1,$2,NULL);}   
     | stmt                   {$$=$1;}
;

exp:   NUM                              
     | ID                     {$1->Gentry = GLookup($1->stringVal); $1->Lentry=  LLookup($1->stringVal); 
                              if($1->Lentry == NULL) if($1->Gentry == NULL) 
                              {printf("undeclared variable %s\n",$1->stringVal);exit(1);}Variable($1);$$ = $1;}
	 | ID'['exp']'            {$1->Gentry = GLookup($1->stringVal); if($1->Gentry == NULL) 
                              {printf("undeclared array %s\n",$1->stringVal);exit(1);}Array($1);$1->left=$3;checkindex($3);$$ = $1;}
     | ID'('Arglist')'        {$1->Gentry = GLookup($1->stringVal); $1->Lentry=  LLookup($1->stringVal); 
                              if($1->Lentry == NULL) if($1->Gentry == NULL) 
                              {printf("undeclared function %s\n",$1->stringVal);exit(1);}Function($1);
                              $1->Arglist=arghead;checkarg($1);arghead=NULL;$$ = $1;}
     | exp PLUS exp		      {$$ = Createtree(0,INTTYPE,NULL,PLUS,$1,$3,NULL);}
	 | exp MINUS exp          {$$ = Createtree(0,INTTYPE,NULL,MINUS,$1,$3,NULL);}
	 | exp MUL exp	          {$$ = Createtree(0,INTTYPE,NULL,MUL,$1,$3,NULL);}
	 | exp DIV exp	          {$$ = Createtree(0,INTTYPE,NULL,DIV,$1,$3,NULL);}
	 | exp MOD exp		      {$$ = Createtree(0,INTTYPE,NULL,MOD,$1,$3,NULL);}
	 | exp LT exp	          {$$ = Createtree(0,BOOLTYPE,NULL,LT,$1,$3,NULL);}
     | exp GT exp	          {$$ = Createtree(0,BOOLTYPE,NULL,GT,$1,$3,NULL);}
     | exp LE exp	          {$$ = Createtree(0,BOOLTYPE,NULL,LE,$1,$3,NULL);}
	 | exp GE exp	          {$$ = Createtree(0,BOOLTYPE,NULL,GE,$1,$3,NULL);}
	 | exp EQ exp	          {$$ = Createtree(0,BOOLTYPE,NULL,EQ,$1,$3,NULL);}
	 | exp NEQ exp	          {$$ = Createtree(0,BOOLTYPE,NULL,NEQ,$1,$3,NULL);}
     | exp AND exp	          {$$ = Createtree(0,BOOLTYPE,NULL,AND,$1,$3,NULL);}
     | exp OR exp	          {$$ = Createtree(0,BOOLTYPE,NULL,OR,$1,$3,NULL);}
     | NOT exp	              {$$ = Createtree(0,BOOLTYPE,NULL,NOT,$2,NULL,NULL);}         
	 | '('exp')'		      {$$ = $2;}

;
	
stmt: exp ASGN exp';'                             {$$ = Createtree(0,0,'=',ASGN,$1,$3,NULL);}
    | READ '('exp')'';'                           {$$ = Createtree(0,0,NULL,READ,$3,NULL,NULL);}
	| WRITE '('exp')'';'                          {$$ = Createtree(0,0,NULL,WRITE,$3,NULL,NULL);}
	| IF '('exp')' THEN Slist ELSE Slist ENDIF';' {$$ = Createtree(0,0,NULL,IF,$3,$6,$8);}
	| IF '('exp')' THEN Slist ENDIF';'            {$$ = Createtree(0,0,NULL,IF,$3,$6,NULL);}
	| WHILE '('exp')' DO Slist ENDWHILE';'        {$$ = Createtree(0,0,NULL,WHILE,$3,$6,NULL);}
	| DO Slist WHILE '('exp')'';'                 {$$ = Createtree(0,0,NULL,DO,$5,$2,NULL);}
	| REPEAT Slist UNTIL '('exp')'';'             {$$ = Createtree(0,0,NULL,REPEAT,$5,$2,NULL);}
	| BREAK';'                                    {$$ = Createtree(0,0,NULL,BREAK,NULL,NULL,NULL);}
    | CONTINUE';'                                 {$$ = Createtree(0,0,NULL,CONTINUE,NULL,NULL,NULL);}
;

Arglist: Arglist ',' exp           {Arginstall($3);}
       | exp                       {Arginstall($1);}
;

%%

void yyerror(char *s)
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
    out=fopen(argv[2],"w");
	yyparse();
    return 0;
}
void checkindex(struct tnode* node)
{
	int type=gettype(node);
	if(type != INTTYPE)
	{
		printf("invalid array size");
		exit(1);
	}
}

void checkarg(struct tnode* node)
{
    struct parameter *para=node->Gentry->paralist;
    struct argument *arg=getarg();
    if(para == NULL && arg == NULL) return;
    while(para!=NULL && arg !=NULL)
    {
        if(para->type==gettype(arg->node))
        {
            para=para->next;
            arg=arg->prev;
            continue;
        }
        printf("parameter %s mismatch ",node->stringVal);
        exit(1);
    
    }
    if(!(para==NULL && arg== NULL))
    {
        printf("parameter %s mismatch",node->stringVal);
        exit(1);
    }
}

void Variable(struct tnode *node)
{
    int design = getdesign(node->stringVal);
    if(design != VARIABLE)
    {    
        printf("ERROR: variable id %s invalid \n",node->stringVal);
        exit(1);
    }
}
void Array(struct tnode *node)
{
    int design = getdesign(node->stringVal);
    if(design != ARRAY)
    { 
        printf("ERROR: variable array %s invalid \n",node->stringVal);
        exit(1);
    }
}
void Function(struct tnode* node)
{
    int design=getdesign(node->stringVal);
    if(design!=FUNCTION)
    {
        printf("ERROR:Function %s invalid",node->stringVal);
        exit(1);
    }
}

int getdesign(char *name)
{
   struct Lsymbol *ptr= Lsymboltable;
    while(ptr!=NULL)
    {
        if(!(strcmp(name,ptr->name)))
        {
            return VARIABLE;
        }
        ptr=ptr->next;
    }

    struct Gsymbol *ptr2 = Gsymboltable;
    while(ptr2 != NULL)
    {
        if(!(strcmp(name,ptr2->name)))
        {
            return ptr2->design;
        }
        ptr2 = ptr2->next;
    }
    return 0;
}
