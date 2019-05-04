%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "linkedList.h"
    int pass = 1;
    int currentLine = 1;
    FILE* fout;
    struct linkedList *head = NULL;
    int getAddress(int line);
%}

%%

\n              {
                    switch(pass)
                    {
                        case 1 : currentLine++; break;
                        case 2 : fprintf(fout,"\n");
                    }
                }

((L[0-9]+)|(F[0-9]+)|(MAIN))/": "   {
                                                    switch(pass)
                                                    {
                                                        case 1 : head = addLabel(head,yytext,getAddress(currentLine));
                                                    }
                                                }

": "            {}

((L[0-9]+)|(F[0-9]+)|(MAIN))        {
                                        switch(pass)
                                        {
                                            case 2 : fprintf(fout,"%d",getLabelAddress(head,yytext));
                                        }
                                    }

(.)             {
                    switch(pass)
                    {
                        case 2: fprintf(fout,"%c",*yytext);
                    }
                }


%%

int yywrap()
{
    if(pass == 1)
    {
        pass = 2;
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