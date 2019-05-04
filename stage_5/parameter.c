#include "parameter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include "y.tab.h"

void Parainstall(char* name, int type){
    struct parameter* temp = malloc(sizeof(struct parameter));
    temp->name = name;
    temp->type = type;
    temp->next = NULL;
    if (parahead == NULL) {
        parahead = temp;
        return;
    }
    struct parameter* ptr = parahead;
    while (ptr != NULL) {
        if (!(strcmp(name, ptr->name))) {
            printf("multiple instances of variable %s declared on function", ptr->name);
            exit(1);
        }
        ptr = ptr->next;
    }
    temp->next = parahead;
    parahead = temp;
}
void checkpara(struct parameter* ptr1, struct parameter* ptr2){
    if (ptr1 == NULL && ptr2 == NULL)
        return;
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->type == ptr2->type)
            if (!(strcmp(ptr1->name, ptr2->name))) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
                continue;
            }
        printf(" parameter mismatch b/w fun definition and declaration");
        exit(1);
    }
    if (!(ptr1 == NULL && ptr2 == NULL)) {
        printf(" parameter mismatch b/w fun definition and declaration");
        exit(1);
    }
}
void paraprint(struct parameter* node){
    struct parameter* ptr = node;
    if (ptr != NULL) {
        printf("parameter list\n");
        printf("name   type\n");
        while (ptr != NULL) {
            printf("%s	%d	\n", ptr->name, ptr->type);
            ptr = ptr->next;
        }
    }
}
struct argument* Arginstall(struct tnode* node){
    struct argument* temp = malloc(sizeof(struct argument));
    temp->node = node;
    temp->prev = NULL;
    temp->next = NULL;
    if (arghead == NULL) {
        arghead = temp;
        return temp;
    }
    struct argument* ptr = arghead;
    while (1) {
        if (ptr->next == NULL)
            break;
        ptr = ptr->next;
    }
    temp->prev = ptr;
    ptr->next = temp;
    return temp;
}
struct argument* getarg(){
    struct argument* ptr = arghead;
    if (ptr == NULL)
        return ptr;
    while (1) {
        if (ptr->next == NULL)
            break;
        ptr = ptr->next;
    }
    return ptr;
}