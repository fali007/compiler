#include "symbol.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "parameter.h"
#include "y.tab.h"

void Ginstall(char* name, int type, int size, int design, struct parameter* paralist)
{
    struct Gsymbol* temp = malloc(sizeof(struct Gsymbol));
    temp->name = name;
    temp->type = type;
    temp->size = size;
    temp->binding = 4096;
    temp->paralist = paralist;
    if (size == -1)
        temp->flabel = getflabel();
    temp->design = design;
    temp->next = NULL;

    if (Gsymboltable == NULL) {
        Gsymboltable = temp;
        return;
    }

    struct Gsymbol* ptr = Gsymboltable;
    while (1) {
        if (!(strcmp(ptr->name, name))) {
            printf(" Multiple instances of global variable '%s' declared\n", name);
            exit(1);
        }
        if (ptr->size > 0)
            temp->binding += ptr->size;
        if (ptr->next == NULL)
            break;
        ptr = ptr->next;
    }
    ptr->next = temp;
    return;
}

struct Gsymbol* GLookup(char* name)
{
    if (Gsymboltable == NULL) {
        printf(" empty Global symbol table\n");
        exit(1);
    }

    struct Gsymbol* ptr = Gsymboltable;
    while (ptr != NULL) {
        if (!(strcmp(ptr->name, name)))
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

int getflabel()
{
    return nextflabel++;
}

void Gprinttable()
{
    struct Gsymbol* temp = Gsymboltable;

    if (temp == NULL) {
        printf("Global Symbol table is empty");
        return;
    }
    else {
        printf("Global symbol table :\n");
        printf("name\ttype\tsize\tbinding\tdesign   \n");
        while (temp != NULL) {
            printf("%s\t%d\t%d\t%d\t%d	\n", temp->name, temp->type, temp->size, temp->binding, temp->design);
            if (temp->design == FUNCTION) {
                printf("function label");
                printf("  F%d \n\n", temp->flabel);
                paraprint(temp->paralist);
            }
            temp = temp->next;
        }
    }
}
struct Lsymbol* Linstall(char* name, int type)
{
    struct Lsymbol* temp = malloc(sizeof(struct Lsymbol));
    temp->name = name;
    temp->type = type;
    temp->binding = 1;
    temp->next = NULL;
    if (Lsymboltable == NULL) {
        Lsymboltable = temp;
        return temp;
    }
    struct Gsymbol* ptr = Gsymboltable;
    while (ptr != NULL) {
        if (ptr->design == FUNCTION)
            if (!(strcmp(ptr->name, name))) {
                printf("local variable cant take fun name");
                exit(1);
            }
        if (ptr->next == NULL)
            break;
        ptr = ptr->next;
    }
    struct Lsymbol* ptr2 = Lsymboltable;
    while (1) {
        if (!(strcmp(ptr2->name, name))) {
            printf(" Multiple instances of local variable '%s' declared\n", name);
            exit(1);
        }

        if (ptr2->next == NULL)
            break;
        ptr2 = ptr2->next;
    }
    if (ptr2->binding >= 1)
        temp->binding = ptr2->binding + 1;
    ptr2->next = temp;
    return temp;
}

struct Lsymbol* LLookup(char* name)
{
    if (Lsymboltable == NULL)
        return NULL;
    struct Lsymbol* ptr = Lsymboltable;
    while (ptr != NULL) {
        if (!(strcmp(ptr->name, name)))
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}
void Lparainstall()
{
    if (parahead != NULL) {
        int i = -3;
        struct parameter* ptr = parahead;
        while (ptr != NULL) {
            char* name = ptr->name;
            int type = ptr->type;
            struct Lsymbol* temp = Linstall(name, type);
            temp->binding = i--;
            ptr = ptr->next;
        }
    }
}
void Lprinttable()
{
    struct Lsymbol* temp = Lsymboltable;

    if (temp == NULL) {
        printf("Local Symbol table is empty");
        return;
    }
    else {
        printf("\nlocal symbol table:\n");
        printf("name   type	 binding      \n");
        while (temp != NULL) {
            printf("%s	%d	%d \n", temp->name, temp->type, temp->binding);
            temp = temp->next;
        }
    }
}