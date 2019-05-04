#ifndef PARAMETER_H
#define PARAMETER_H
#include "tree.h"
struct parameter 
{
    char *name;
    int type;
    struct parameter *next;
};
void Parainstall(char *name,int type);
void checkpara(struct parameter *ptr1,struct parameter *ptr2);
void paraprint(struct parameter *node);
struct argument
{
    struct tnode* node;
    struct argument *prev;
    struct argument *next;
};
struct argument *Arginstall(struct tnode *node);
struct argument *getarg();

#endif
