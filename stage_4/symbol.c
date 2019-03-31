#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern struct Gsymbol* symbolTable = NULL;

void varinstall(int type, struct tnode* varList)
{
    if (varList->nodetype == CONN) {
        varinstall(type, varList->left);
        varinstall(type, varList->right);
    }
    else {
        Install(varList->stringVal, type, varList->intVal);
        if (varList->left != NULL) {
            struct Gsymbol* temp = Lookup(varList->stringVal);
            temp->row = varList->left->intVal;
            temp->column = varList->right->intVal;
        }
    }
}

void Install(char* name, int type, int size)
{
    struct Gsymbol* temp = malloc(sizeof(struct Gsymbol));
    temp->name = name;
    temp->type = type;
    temp->size = size;
    temp->binding = 4096;
    temp->next = NULL;
    temp->row = 0;
    temp->column = 0;
    if (symbolTable == NULL) {
        symbolTable = temp;
        return;
    }
    struct Gsymbol* ptr = symbolTable;
    while (1) {
        if (!(strcmp(ptr->name, name))) {
            printf("Multiple instances of variable '%s' declared\n", name);
            exit(1);
        }
        temp->binding += ptr->size;
        if (ptr->next == NULL)
            break;
        ptr = ptr->next;
    }
    ptr->next = temp;
}

struct Gsymbol* Lookup(char* name)
{
    if (symbolTable == NULL) {
        printf("empty symbol table\n");
        exit(1);
    }
    struct Gsymbol* ptr = symbolTable;
    while (ptr != NULL) {
        if (!(strcmp(ptr->name, name))) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void printtable()
{
    struct Gsymbol* temp = symbolTable;

    if (temp == NULL) {
        printf("Symbol table is empty");
        return;
    }
    else {
        printf("name	type	size	bind	row	column \n");
        while (temp != NULL) {
            printf("%s	%d	%d	%d	%d	%d\n", temp->name, temp->type, temp->size, temp->binding, temp->row, temp->column);
            temp = temp->next;
        }
    }
}
