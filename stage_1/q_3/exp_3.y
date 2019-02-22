%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "exprtree.h"
	#include "exprtree.c"
	int yylex(void);
	FILE* fout;
    struct tnode* root;
%}

%union{
	struct tnode *no;
	//char str;
}
%type <no> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END	{
				$$ = $2;
				printf("Answer : %d\n",evaluate($1));
				//preorder($1);
				root=$1;
				return 0;
			}
		;

expr : PLUS expr expr		{$$ = makeOperatorNode('+',$2,$3);}
	 | MINUS expr expr  	{$$ = makeOperatorNode('-',$2,$3);}
	 | MUL expr expr	{$$ = makeOperatorNode('*',$2,$3);}
	 | DIV expr expr	{$$ = makeOperatorNode('/',$2,$3);}
	 | '(' expr ')'		{$$ = $2;}
	 | NUM			{$$ = $1;}
	 ;

%%

int yyerror(char const *s)
{
    printf("yyerror %s",s);
	return 0;
}


int main(void) {
    fout = fopen("out.xsm","w");
	yyparse();
	initialize(fout);
    codegen(root,fout);
   // storeReg0(fout,'a');
    // print_static_var(fout,'a');
    fprintf(fout,"INT 10\n");
	return 0;
}
