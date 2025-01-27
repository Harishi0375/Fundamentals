/*
CH-230-A
a7_p1.h
Harishi Velavan
hvelavan@jacobs-university.de
*/

// linked_list.h

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct List {
    int info;
    struct List* next;
};

struct List* createList(int info);
void insertAtBeginning(struct List** head, int info);
void insertAtEnd(struct List** head, int info);
void printList(struct List* head);
void deleteFirstList(struct List** head);
void freeList(struct List* head);

#endif // LINKED_LIST_H

