#ifndef TREE_H
#define TREE_H
#include "parameter.h"

struct tnode {
    int nodetype;
    int type;
    int intVal;
    char* stringVal;
    struct Gsymbol* Gentry;
    struct Lsymbol* Lentry;
    struct argument* Arglist;
    struct tnode *left, *right, *ptr;
};
struct tnode* Createtree(int intVal, int type, char* stringVal, int nodetype, struct tnode* left, struct tnode* right, struct tnode* ptr);
void Typecheck(struct tnode* node);
int gettype(struct tnode* node);
extern int dectype;
#endif