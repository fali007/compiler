%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "link.h"
    int p = 1;
    int current = 1;
    FILE* fout;
    struct list *head = NULL;
    int getAddress(int line);
%}

%%

\n              {
                    switch(p)
                    {
                        case 1 : current++; break;
                        case 2 : fprintf(fout,"\n");
                    }
                }

L[0-9]+/":"     {
                    if(p == 1)
                    {
                        head = addLabel(head,yytext,getAddress(current));
                    }
                }

":"            {}

L[0-9]+         {
                    if(p == 2)
                    {
                     fprintf(fout,"%d",getLabelAddress(head,yytext));
                    }
                }

(.)             {
                    if(p == 2)
                    {
                     fprintf(fout,"%c",*yytext);
                    }
                }


%%

int yywrap()
{
    if(p == 1)
    {
        p++;
        rewind(yyin);
        return 0;
    }
    return 1;
}

int getAddress(int line)
{
    int address = 2056+(line-9)*2;
    return address;
}

int main(int argc, char* argv[])
{ 
    yyin = fopen(argv[1],"r");
    fout = fopen(argv[2],"w");
    yylex();
}