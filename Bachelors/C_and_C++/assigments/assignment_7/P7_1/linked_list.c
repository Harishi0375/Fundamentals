/*
CH-230-A
a7_p1.c
Harishi Velavan
hvelavan@jacobs-university.de
*/

// linked_list.c

#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

struct List* createList(int info) {
    struct List* newList = (struct List*)malloc(sizeof(struct List));
    newList->info = info;
    newList->next = NULL;
    return newList;
}

void insertAtBeginning(struct List** head, int info) {
    struct List* newList = createList(info);
    newList->next = *head;
    *head = newList;
}

void insertAtEnd(struct List** head, int info) {
    struct List* newList = createList(info);
    if (*head == NULL) {
        *head = newList;
    } else {
        struct List* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newList;
    }
}

void printList(struct List* head) {
    struct List* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

void deleteFirstList(struct List** head) {
    if (*head == NULL) {
        return;
    }

    struct List* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void freeList(struct List* head) {
    struct List* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
