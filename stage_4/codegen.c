#include <stdio.h>
#include <stdlib.h>
#include "codegen.h"
#include "y.tab.h"
#include "symbol.h"

void initialize()
{
    fprintf(out, "0\n2056\n0\n0\n0\n0\n0\n0\n");
}
void stack0()
{
    int add = 4095;
    if (symbolTable == NULL) {
        fprintf(out, "MOV SP,%d\n", add);
        return;
    }
    struct Gsymbol* ptr = symbolTable;
    while (ptr != NULL) {
        if (ptr->next == NULL)
            add = ptr->binding + ptr->size - 1;
        ptr = ptr->next;
    }
    fprintf(out, "MOV SP,%d\n", add);
}
void exit0()
{
    fprintf(out, "INT 10\n");
}

int codegen(struct tnode* node)
{
    int reg, binding, label1, label2, l, m;
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

    case STRING:
        reg = getreg();
        fprintf(out, "MOV R%d, \"%s\"\n", reg, node->stringVal);
        return reg;
        break;

    case ID:
        reg = getvalue(node);
        return reg;
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
void freereg()
{
    if (regno > 0)
        regno--;
}
int getlabel()
{
    return label++;
}

int getvalue(struct tnode* node)
{
    VerifyIndex(node);
    int reg;
    if (node->right != NULL) {
        int bindReg = getbinding(node);
        fprintf(out, "MOV R%d, [R%d]\n", bindReg, bindReg);
        return bindReg;
    }
    if (node->left != NULL) {
        reg = codegen(node->left);
        fprintf(out, "ADD R%d, %d\n", reg, node->varNode->binding);
        fprintf(out, "MOV R%d, [R%d]\n", reg, reg);
        return reg;
    }
    reg = getreg();
    fprintf(out, "MOV R%d, [%d]\n", reg, node->varNode->binding);
    return reg;
}

int getbinding(struct tnode* node)
{
    VerifyIndex(node);
    if (node->right != NULL) {
        int rowSize = node->varNode->row;
        int columnSize = node->varNode->column;
        if (rowSize == 0 || columnSize == 0) {
            printf("Error: Trying to access variable like 2d array\n");
            exit(1);
        }
        int rowReg = codegen(node->left);
        int columnReg = codegen(node->right);
        fprintf(out, "MUL R%d, %d\n", rowReg, columnSize);
        fprintf(out, "ADD R%d, R%d\n", rowReg, columnReg);
        fprintf(out, "ADD R%d, %d\n", rowReg, node->varNode->binding);
        freereg();
        return rowReg;
    }
    if (node->left != NULL) {
        int reg = codegen(node->left);
        fprintf(out, "ADD R%d, %d\n", reg, node->varNode->binding);
        return reg;
    }
    int reg = getreg();
    fprintf(out, "MOV R%d, %d\n", reg, node->varNode->binding);
    return reg;
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

void VerifyIndex(struct tnode* node) 
{
    int size = node->varNode->size;
    if (node->left != NULL) {
        int exitLabel = getlabel();
        int continueLabel = getlabel();
        int reg = codegen(node->left);
        int bufReg1 = getreg();
        fprintf(out, "MOV R%d, R%d\n", bufReg1, reg);
        int bufReg2 = getreg();
        fprintf(out, "MOV R%d, 0\n", bufReg2);
        fprintf(out, "LE R%d, R%d\n", bufReg2, bufReg1); 
        fprintf(out, "JZ R%d, L%d\n", bufReg2, exitLabel);
        fprintf(out, "MOV R%d, %d\n", bufReg2, node->varNode->size);
        fprintf(out, "SUB R%d, R%d\n", bufReg2, bufReg1);
        fprintf(out, "MOV R%d, 0\n", bufReg1);
        fprintf(out, "GT R%d, R%d\n", bufReg2, bufReg1); 
        fprintf(out, "JZ R%d, L%d\n", bufReg2, exitLabel);
        fprintf(out, "JMP L%d\n", continueLabel);
        fprintf(out, "L%d: MOV R%d, \"index error\"\n", exitLabel, bufReg1);
        write(bufReg1);
        fprintf(out, "INT 10\n");
        fprintf(out, "L%d: ", continueLabel);
        freereg();
        freereg();
        freereg();
    }
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