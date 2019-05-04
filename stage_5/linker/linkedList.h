#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct linkedList
{
    char* label;
    int address;
    struct linkedList *next;
};

struct linkedList* addLabel(struct linkedList *head, char* label, int address);
int getLabelAddress(struct linkedList *head, char* label);

#endif