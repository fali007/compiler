struct list
{
    char* label;
    int address;
    struct list *next;
};

struct list* addLabel(struct list *head, char* label, int address);
int getLabelAddress(struct list *head, char* label);
