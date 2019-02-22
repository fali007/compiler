struct linkedList
{
    char* label;
    int address;
    struct linkedList *next;
};

struct linkedList* pushabel(struct linkedList *head, char* label, int address);
int getLabelAddress(struct linkedList *head, char* label);

