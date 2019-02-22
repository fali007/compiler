struct linkedList* pushlabel(struct linkedList *head, char* label, int address)
{
    struct linkedList *temp = malloc(sizeof(struct linkedList));
    temp->label = strdup(label);
    temp->address = address;
    temp->next = head;
    head = temp;
    return head;
}

int getLabelAddress(struct linkedList *head, char* label)
{
    struct linkedList *current = head;
    while(current != NULL)
    {
        if(!strcmp(label,current->label)) return current->address;
        current = current->next;
    }
    printf("ERROR: Undefined label encountered\n");
    exit(1);
}
