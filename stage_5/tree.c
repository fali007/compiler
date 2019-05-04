#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include "y.tab.h"

struct tnode* Createtree(int intVal, int type, char* stringVal, int nodetype, struct tnode* left, struct tnode* right, struct tnode* ptr)
{
    struct tnode* temp = malloc(sizeof(struct tnode));
    temp->nodetype = nodetype;
    temp->type = type;
    temp->intVal = intVal;
    temp->stringVal = stringVal;
    temp->left = left;
    temp->right = right;
    temp->ptr = ptr;
    temp->Gentry = NULL;
    temp->Lentry = NULL;
    temp->Arglist = NULL;
    Typecheck(temp);
    return temp;
}
void Typecheck(struct tnode* node)
{
    int leftdata = gettype(node->left);
    int rightdata = gettype(node->right);
    switch (node->nodetype) {
    case PLUS:
    case MINUS:
    case MUL:
    case DIV:
    case MOD:
    case EQ:
    case NEQ:
    case LT:
    case GT:
    case LE:
    case GE:

        if (leftdata == INTTYPE && rightdata == INTTYPE)
            return;
        printf("type mismatch in exp\n");
        exit(1);
        break;
    case AND:
    case OR:
        if (leftdata == BOOLTYPE && rightdata == BOOLTYPE)
            return;
        printf("type mismatch in AND / OR");
        exit(1);
        break;
    case NOT:
        if(leftdata == BOOLTYPE)
            return;
        printf("type mismatch in NOT ");
        exit(1);
        break;
    case RETURN:
        if (leftdata == dectype)
            return;
        printf("invalid return type");
        exit(1);
        break;
    case WRITE:
        if (leftdata == INTTYPE || leftdata == STRTYPE)
            return;
        printf("type mismatch in write stmt");
        exit(1);
        break;
    case READ:
        if (node->left->nodetype == ID)
            return;
        printf("type mismatch in read stmt");
        exit(1);
        break;
    case ASGN:
        if (leftdata == INTTYPE && rightdata == INTTYPE)
            return;
        if (leftdata == STRTYPE && rightdata == STRTYPE)
            return;
        printf("type mismatch in assignment ");
        exit(1);
        break;
    case IF:
    case WHILE:
        if (leftdata == BOOLTYPE)
            return;
        printf("type mismatch in conditional stmt");
        exit(1);
        break;
    default:
        break;
    }
    return;
}
int gettype(struct tnode* node)
{
    if (node == NULL)
        return 0;
    int datatype = node->type;
    if (node->nodetype == ID) {
        if (node->Lentry != NULL)
            datatype = node->Lentry->type;
        if (node->Gentry != NULL)
            datatype = node->Gentry->type;
    }
    return datatype;
}