#ifndef CODEGEN_H
#define CODEGEN_H

#include "tree.h"

void initialize();
void stack0();
void exit0();
int codegen(struct tnode *node);
struct stack
{
    int label;
    struct stack *next;
};
int getreg();
void freereg();
int getlabel();
int getvalue(struct tnode* node);   
int getbinding(struct tnode* node); 
void read(int reg);
void write(int reg);
void VerifyIndex(struct tnode *node);         
extern FILE *out;
extern struct Gsymbol *symbolTable;
static int regno = 0;
static int label = 0;
static struct stack *lentry = NULL;
static struct stack *lexit = NULL;
struct stack* push(struct stack* top,int label);
struct stack* pop(struct stack *top);
int look(struct stack *top);
#endif