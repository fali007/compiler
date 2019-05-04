#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "linkedList.h"


struct linkedList* addLabel(struct linkedList *head, char* label, int address)
{
    struct linkedList *temp = malloc(sizeof(struct linkedList));
    temp->label = strdup(label);
    temp->address = address;
    temp->next = NULL;
    if(head == NULL) return temp;
    struct linkedList *iterator = head;
    while(1)                                                   
    {
        if(iterator->next == NULL) break;                         
        iterator = iterator->next;
    }
    iterator->next = temp;
    return head;
}

int getLabelAddress(struct linkedList *head, char* label)
{
    struct linkedList *iterator = head;
    while(iterator != NULL)
    {
        if(!strcmp(label,iterator->label)) return iterator->address;
        iterator = iterator->next;
    }
    printf("ERROR: Undefined label '%s' encountered\n",label);
    exit(1);
}
