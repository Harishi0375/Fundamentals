/*
  CH-230-A
  a6_p8.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

struct List
{
    int info; //data stored in the List
    struct List *next; //pointer to the next List in the list   
};

struct List* createList(int info) {
    struct List* newList = (struct List*)malloc(sizeof(struct List));
    newList->info = info;
    newList->next = NULL;
    return newList;
}

void insertAtBeginning(struct List** head, int info) {
    struct List *newList = createList(info);
    newList->next = *head;
    *head = newList;
}

void insertAtEnd(struct List** head, int info) {
    struct List *newList = createList(info);
    if (*head == NULL) {
        *head = newList;
    } else {
        struct List *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newList;
    }
}

void printList(struct List* head) {
    struct List *temp = head;
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


int main()
{
    char ch;
    int info;
    struct List* head = NULL;

    while (1)
    {
        scanf(" %c",&ch);
        switch (ch)
        {
        case 'a':
            scanf("%d", &info);
            insertAtEnd(&head, info);
            break;
        
        case 'b':
            scanf("%d", &info);
            insertAtBeginning(&head, info);
            break;

        case 'r':
            scanf("%d", &info);
            deleteFirstList(&head);
            break;
        
        case 'p':
            printList(head);
            break;
        
        case 'q':
            freeList(head);
            exit(0);

        default:
            break;
        }
    }
    
}