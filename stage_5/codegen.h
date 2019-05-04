#ifndef CODEGEN_H
#define CODEGEN_H
#include "tree.h"
void initialize();
void funcodegen(struct tnode *node);
int codegen(struct tnode *node);
int getreg();
int freereg();
int getlabel();
int getlocal();
int getvalue(struct tnode *node);
int getbinding(struct tnode*node);
int fungenvalue(struct tnode *node);
void read(int reg);
void write(int reg);
extern FILE* out;
extern struct Gsymbol *Gsymboltable;
extern struct Lsymbol *Lsymboltable;
static int regno = 0;
static int label = 0;
struct stack
{
    int label;
    struct stack *next;
};
struct stack* push(struct stack* top, int label);
struct stack* pop(struct stack* top);
static struct stack *lentry = NULL;
static struct stack *lexit = NULL;
#endif