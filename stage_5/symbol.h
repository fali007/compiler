#ifndef SYMBOL_H
#define SYMBOL_H
#include "parameter.h"
int yylex();
void yyerror(char* s);
extern FILE* yyin;
FILE* out;
int dectype, ctype;
void checkindex(struct tnode* node);
void checkarg(struct tnode* node);
void Variable(struct tnode* node);
void Array(struct tnode* node);
void Function(struct tnode* node);
int getdesign(char* name);
struct Gsymbol* Gsymboltable = NULL;
struct Lsymbol* Lsymboltable = NULL;
struct parameter* parahead = NULL;
struct argument* arghead = NULL;
int nextflabel = 0;
int getflabel();

struct Gsymbol {
    char* name;
    int type;
    int size;
    int binding;
    struct parameter* paralist;
    int flabel;
    int design;
    struct Gsymbol* next;
};
void Ginstall(char* name, int type, int size, int design, struct parameter* paralist);
struct Gsymbol* GLookup(char* name);
void Gprinttable();
struct Lsymbol {
    char* name;
    int type;
    int binding;
    struct Lsymbol* next;
};
struct Lsymbol* Linstall(char* name, int type);
struct Lsymbol* LLookup(char* name);
void Lparainstall();
void Lprinttable();

#endif