#include "codegen.h"
#include<stdio.h>
#include<stdlib.h>
#include "tree.h"
#include "symbol.h"
#include "y.tab.h"

void initialize(){
    struct Gsymbol *ptr=Gsymboltable;
    int size=0;
    while(ptr!=NULL){
        if(ptr->size>0)
            size+=ptr->size;
        ptr=ptr->next;

    }
    int stackadd=size+4095;
    fprintf(out,"0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(out,"MOV SP, %d\n",stackadd);
    fprintf(out,"MOV BP, %d\n",stackadd);
    fprintf(out,"PUSH R0\n");
    fprintf(out,"CALL MAIN\n");
    fprintf(out,"INT 10\n");
}
void fungen(struct tnode* node)
{
    fprintf(out,"PUSH BP\n");
    fprintf(out,"MOV BP, SP\n");
    int local=getlocal();
    fprintf(out,"ADD SP,%d\n",local);
    codegen(node);
}
int codegen(struct tnode* node)
{
     int reg, binding, label1, label2, l, m,new,count;
    switch (node->nodetype) {

    case CONN:
        codegen(node->left);
        codegen(node->right);
        return 0;
        break;

    case NUM:
        reg = getreg();
        fprintf(out, "MOV R%d, %d\n", reg, node->intVal);
        return reg;
        break;

    case ID:
       if(node->Lentry!=NULL)
         {
        reg = getvalue(node);
        return reg;
         }
        else if(node->Gentry!=NULL)
        {
            if(node->Gentry->design == VARIABLE || node->Gentry->design == ARRAY)
            {
                reg=getvalue(node);
                return reg;
            }
            else if(node->Gentry->design == FUNCTION)
            {
                reg=getfunvalue(node);
                return reg;
            }
        }
        break;


    case READ:
        binding = getbinding(node->left);
        read(binding);
        freereg();
        return 0;
        break;

    case WRITE:
        reg = codegen(node->left);
        write(reg);
        freereg();
        return 0;
        break;

    case ASGN:
        reg = codegen(node->right);
        binding = getbinding(node->left);
        fprintf(out, "MOV [R%d], R%d\n", binding, reg);
        freereg();
        freereg();
        return 0;
        break;

    case IF:
        label1 = getlabel();
        reg = codegen(node->left);
        fprintf(out, "JZ R%d, L%d\n", reg, label1);
        freereg();
        codegen(node->right);
        if (node->ptr == NULL)
            fprintf(out, "L%d: ", label1);
        else {
            label2 = getlabel();
            fprintf(out, "JMP L%d\n", label2);
            fprintf(out, "L%d: ", label1);
            codegen(node->ptr);
            fprintf(out, "L%d: ", label2);
        }
        return 0;
        break;

    case WHILE:
        label1 = getlabel();
        label2 = getlabel();
        lentry = push(lentry, label1);
        lexit = push(lexit, label2);
        fprintf(out, "L%d: ", label1);
        reg = codegen(node->left);
        fprintf(out, "JZ R%d, L%d\n", reg, label2);
        freereg();
        codegen(node->right);
        fprintf(out, "JMP L%d\n", label1);
        fprintf(out, "L%d: ", label2);
        lentry = pop(lentry);
        lexit = pop(lexit);
        return 0;
        break;

    case DO:
        codegen(node->right);
        label1 = getlabel();
        label2 = getlabel();
        fprintf(out, "L%d: ", label1);
        reg = codegen(node->left);
        fprintf(out, "JZ R%d, L%d\n", reg, label2);
        freereg();
        codegen(node->right);
        fprintf(out, "JMP L%d\n", label1);
        fprintf(out, "L%d: ", label2);
        break;

    case REPEAT:
        codegen(node->right);
        label1 = getlabel();
        label2 = getlabel();
        fprintf(out, "L%d: ", label1);
        reg = codegen(node->left);
        fprintf(out, "JNZ R%d, L%d\n", reg, label2);
        freereg();
        codegen(node->right);
        fprintf(out, "JMP L%d\n", label1);
        fprintf(out, "L%d: ", label2);
        break;

    case BREAK:
        if (lexit != NULL) {
            int exitLabel = look(lexit);
            fprintf(out, "JMP L%d\n", exitLabel);
        }
        return 0;
        break;

    case CONTINUE:
        if (lentry != NULL) {
            int entryLabel = look(lentry);
            fprintf(out, "JMP L%d\n", entryLabel);
        }
        return 0;
        break;
    case NOT:
       reg=codegen(node->left);
       label1=getlabel();
       label2=getlabel();
       fprintf(out,"JZ R%d,L%d\n",reg,label1);
       fprintf(out,"MOV R%d,0\n",reg);
       fprintf(out,"JMP L%d\n",label2);
       fprintf(out,"L%d:MOV R%d,1\n",label1,reg);
       fprintf(out,"L%d:",label2);
       return reg;
    
    case RETURN:
    reg=codegen(node->left);
    new=getreg();
    fprintf(out,"MOV R%d, BP\n",new);
    fprintf(out,"SUB R%d,2\n",new);
    fprintf(out,"MOV [R%d], R%d\n",new,reg);
    freereg();
    freereg();
    count=getlocal();
    fprintf(out,"SUB SP, %d\n",count);
    fprintf(out,"POP BP\n");
    fprintf(out,"RET\n");
    return 0;
    break;

    default:
        l = codegen(node->left);
        m = codegen(node->right);
        switch (node->nodetype) {
        case PLUS:
            fprintf(out, "ADD R%d, R%d\n", l, m);
            break;
        case MINUS:
            fprintf(out, "SUB R%d, R%d\n", l, m);
            break;
        case MUL:
            fprintf(out, "MUL R%d, R%d\n", l, m);
            break;
        case DIV:
            fprintf(out, "DIV R%d, R%d\n", l, m);
            break;
        case MOD:
            fprintf(out, "MOD R%d, R%d\n", l, m);
            break;
        case GT:
            fprintf(out, "GT R%d, R%d\n", l, m);
            break;
        case LT:
            fprintf(out, "LT R%d, R%d\n", l, m);
            break;
        case EQ:
            fprintf(out, "EQ R%d, R%d\n", l, m);
            break;
        case NEQ:
            fprintf(out, "NE R%d, R%d\n", l, m);
            break;
        case GE:
            fprintf(out, "GE R%d, R%d\n", l, m);
            break;
        case LE:
            fprintf(out, "LE R%d, R%d\n", l, m);
            break;
        case AND:
            fprintf(out, "MUL R%d, R%d\n", l, m);
            break;
        case OR:
            fprintf(out, "ADD R%d, R%d\n", l, m);
            break;
        
        }
        freereg();
        return l;
    }
}
int getreg()
{
    if (regno < 20)
        return regno++;
    else {
        printf("no free Reg\n");
        exit(1);
    }
}
int freereg()
{
    if (regno > 0)
        return regno--;
}
int getlabel()
{
    return label++;
}

int getbinding(struct tnode* node)
{
    if (node->Lentry != NULL) {
        int reg=getreg();
        int bindReg = node->Lentry->binding;
        fprintf(out, "MOV R%d, BP\n",reg);
        fprintf(out,"ADD R%d,%d\n",reg,bindReg);
        return reg;
    }
    else if (node->Gentry != NULL) {
        int bindReg=node->Gentry->binding;
        int reg=getreg();
        fprintf(out, "MOV R%d, %d\n", reg,bindReg);
        if(node->left!=NULL)
        {
            int reg1=codegen(node->left);
            fprintf(out,"ADD R%d,R%d\n",reg,reg1);
            freereg();
        }
        return reg;
    }
 
}

int getvalue(struct tnode* node)
{
    
    int reg = getbinding(node);
    fprintf(out, "MOV R%d, [R%d]\n", reg, reg);
    return reg;
}
int getlocal()
{
    struct Lsymbol *ptr=Lsymboltable;
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    return count;
}

void read(int reg)
{
    int bufReg = getreg();

    fprintf(out, "MOV R%d, \"Read\"\n", bufReg);
    fprintf(out, "PUSH R%d\n", bufReg);
    fprintf(out, "MOV R%d, -1\n", bufReg);
    fprintf(out, "PUSH R%d\n", bufReg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", bufReg);
    fprintf(out, "PUSH R%d\n", bufReg);
    fprintf(out, "CALL 0\n");
    fprintf(out, "POP R%d\n", bufReg);
    fprintf(out, "POP R%d\n", bufReg);
    fprintf(out, "POP R%d\n", bufReg);
    fprintf(out, "POP R%d\n", bufReg);
    fprintf(out, "POP R%d\n", bufReg);

    freereg();
}

void write(int reg)
{
    int bufReg = getreg();

    fprintf(out, "MOV R%d, \"Write\"\n", bufReg);
    fprintf(out, "PUSH R%d\n", bufReg);
    fprintf(out, "MOV R%d,-2\n", bufReg);
    fprintf(out, "PUSH R%d\n", bufReg);
    fprintf(out, "PUSH R%d\n", reg);
    fprintf(out, "PUSH R%d\n", bufReg);
    fprintf(out, "PUSH R%d\n", bufReg);
    fprintf(out, "CALL 0\n");
    fprintf(out, "POP R%d\n", bufReg);
    fprintf(out, "POP R%d\n", bufReg);
    fprintf(out, "POP R%d\n", bufReg);
    fprintf(out, "POP R%d\n", bufReg);
    fprintf(out, "POP R%d\n", bufReg);

    freereg();
}

struct stack* push(struct stack* top, int label)
{
    struct stack* temp = malloc(sizeof(struct stack));
    temp->label = label;
    temp->next = NULL;
    if (top == NULL)
        return temp;
    temp->next = top;
    return temp;
}

struct stack* pop(struct stack* top)
{
    struct stack* temp = top->next;
    free(top);
    return temp;
}

int look(struct stack* top)
{
    return top->label;
}
int getfunvalue(struct tnode* node)
{   int i;
    int current =regno;
    for(i=0;i<current;i++)
        fprintf(out,"PUSH R%d\n",i);
    regno=0;
    struct argument *ptr=node->Arglist;
    while(ptr!=NULL)
    {
        int reg=codegen(ptr->node);
        fprintf(out,"PUSH R%d\n",reg);
        freereg();
        ptr=ptr->next;
    
    }
    fprintf(out,"PUSH R0\n");
    fprintf(out,"CALL F%d\n",node->Gentry->flabel);
    fprintf(out,"POP R%d\n",current);
    regno=current+1;
    ptr=node->Arglist;
    while(ptr!=NULL)
    {
      int reg2=getreg();
      fprintf(out,"POP R%d\n",reg2);
      freereg();
      ptr=ptr->next;
    }
    for(i=current-1;i>=0;i--)
        fprintf(out,"POP R%d\n",i);
    return current;

}
