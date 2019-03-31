#ifndef TREE_H
#define TREE_H
#include "symbol.h"

struct tnode
{
    int nodetype;                   
    int type;
    int intVal;                    
    char *stringVal;              
    struct Gsymbol *varNode;    
    struct tnode *left, *right, *ptr;    
};
struct tnode *Createtree(int intVal, int type,char *stringVal,int nodetype, struct Gsymbol *varNode, struct tnode *left, struct tnode *right,struct tnode *ptr);
void Typecheck(struct tnode* node);
#endif