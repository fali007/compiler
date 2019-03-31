#ifndef SYMBOL_H
#define SYMBOL_H
int yylex();
extern FILE *yyin;
FILE* out;
struct Gsymbol
{
    char* name;              
    int type;               
    int size;                   
    int binding;                
    struct Gsymbol* next;    
    int row;                    
    int column;                 
};
void Install(char *varName, int dataType, int size);    
struct Gsymbol *Lookup(char * varName);             
void printtable();
#endif