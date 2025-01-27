#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
    int info;
    struct linked_list* next;
};

void print_list(struct linked_list* my_list)
{
    while (my_list != NULL)
    {
        printf("%d\n", my_list->info);
        my_list = my_list->next;
    }
}


struct linked_list* createList(int info) 
{
    struct linked_list* newList = (struct linked_list*)malloc(sizeof(struct linked_list));
    newList->info = info;
    newList->next = NULL;
    return newList;
}

