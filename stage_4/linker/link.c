#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "link.h"


struct list* addLabel(struct list *head, char* label, int address)
{
    struct list *temp = malloc(sizeof(struct list));
    temp->label = strdup(label);
    temp->address = address;
    temp->next = NULL;
    if(head == NULL) return temp;
    struct list *ptr = head;
    while(ptr->next!=NULL)                                                   
    {                                 
        ptr = ptr->next;
    }
    ptr->next = temp;
    return head;
}

int getLabelAddress(struct list *head, char* label)
{
    struct list *ptr = head;
    while(ptr != NULL)
    {
        if(!strcmp(label,ptr->label)) 
        return ptr->address;
        ptr = ptr->next;
    }
    printf("ERROR: \n");
    exit(1);
}