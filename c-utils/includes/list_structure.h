#ifndef LIST_STRUCTURE
#define LIST_STRUCTURE
    typedef struct LIST{
        unsigned int N; /*Name id*/
        char Name[40 + 1];
        struct LIST *next;
    } List;
    void Init(List **ptr);
    void Insert(List **ptr, List *tmp);
    int Load(List **L);
    int Load_bin(List **L);
    int Remove(List **ptr, unsigned int Num);
    int Save(List **L);
    void List_display(List *list);
#endif
