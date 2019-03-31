#include "tree.h"
#include<stdlib.h>
#include<stdio.h>
#include "y.tab.h"

struct tnode *Createtree(int intVal, int type,char *stringVal,int nodetype, struct Gsymbol *varNode, struct tnode *left, struct tnode *right,struct tnode *ptr)
{
    struct tnode* temp = malloc(sizeof(struct tnode));  
    temp->nodetype = nodetype;
    temp->type = type;
    temp->intVal = intVal;
    temp->stringVal = stringVal;
    temp->varNode = varNode;
    temp->left = left;
    temp->right = right;
	temp->ptr = ptr;
    Typecheck(temp);                   
    return temp;
};

void Typecheck(struct tnode* node)
{
    int leftdata, rightdata;
    switch (node->nodetype)
    {   
        case PLUS:
        case MINUS:
        case MUL:
        case DIV:
        case MOD:
        case LT:
        case GT:
        case LE:
        case GE:
        case EQ:
        case NEQ:
            if(node->left->nodetype == ID)  leftdata = node->left->varNode->type;
            else leftdata = node->left->type;
            if(node->right->nodetype == ID)  rightdata = node->right->varNode->type;
            else rightdata = node->right->type;
            if(leftdata == rightdata)   return;
            printf("Type mismatch in expression\n"); exit(1);           
            break;
        case IF:
        case WHILE:
            if(node->left->type == BOOLTYPE) return;
            printf("Type mismatch in if/while node\n"); exit(1);
            break;

        case READ:                                                             
            if(node->left->nodetype == ID) return;
            printf("type mismatch in Read node\n"); exit(1);
            break;

        case WRITE:
            if(node->left->nodetype == ID)    if(node->left->varNode->type == INTTYPE || node->left->varNode->type == STRTYPE)    return;
            if(node->left->type == INTTYPE || node->left->type == STRTYPE) return;
            printf("Type mismatch in Write node\n"); exit(1);
            break;

        case ID:
            if(node->right != NULL)
            {

                if(node->right->nodetype == ID) rightdata = node->right->varNode->type;
                else rightdata = node->right->type;
                if(node->left->nodetype == ID) leftdata = node->left->varNode->type;
                else leftdata = node->left->type;
                if(leftdata == rightdata && rightdata == INTTYPE) return;
            }
            else if(node->left != NULL)
            {
                if(node->left->nodetype == ID) leftdata = node->left->varNode->type;
                else leftdata = node->left->type;
                if(leftdata == INTTYPE) return;
            }
            else {return;}
            printf("ERROR: Type mismatch in array declaration index\n");printf("%d,%d\n",leftdata,rightdata); exit(1);    
            break;
      
        case ASGN:
            if(node->left->nodetype == ID)
            {
                leftdata = node->left->varNode->type;
                if(node->right->nodetype == ID) rightdata = node->right->varNode->type;
                else rightdata = node->right->type;
                if(leftdata == rightdata) return;
            }
            printf("Error: Type mismatch in assignment node\n"); exit(1);
						break;
        default:
            break;
     }
}