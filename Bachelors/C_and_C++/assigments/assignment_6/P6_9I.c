/*
  CH-230-A
  a6_p9.c
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>


//My brother gave me few points to write this code
struct List
{
    int info; //data stored in the List
    struct List* next; //pointer to the next List in the list   
};

struct List* createList(int info) { //create list
    struct List* newList = (struct List*)malloc(sizeof(struct List));
    newList->info = info;
    newList->next = NULL;
    return newList;
}

void insertAtBeginning(struct List** head, int info) { //instert value at the beginning 
    struct List* newList = createList(info);
    newList->next = *head;
    *head = newList;
}

void insertAt(struct List* head, int info, int index) {
    struct List* temp = head;
    struct List* newList = createList(info);
    int count = 0;

    // Handle insertion at the beginning of the list
    if (index == 0) {
        newList->next = head;
        return;
    }

    // Traverse the list to find the specified index
    while (temp != NULL) {
        if (count == index - 1) {
            break;
        }
        temp = temp->next;
        ++count;
    }

    // Handle insertion at the specified index
    if (temp != NULL) {
        struct List* next = temp->next;
        temp->next = newList;
        newList->next = next;
    } else {
        printf("Invalid position!\n");
        // Handle the case when index is out of range
    }
}

void reverseList(struct List** head) {
    struct List* prev = NULL;
    struct List* current = *head;
    struct List* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void insertAtEnd(struct List** head, int info) { //insert before end of node
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

void printList(struct List* head) { //print list
    struct List* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

void deleteFirstList(struct List** head) { //delete first value in list
    if (*head == NULL) {
        return;
    }

    struct List* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void freeList(struct List* head) { //empties list
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
    int index; 

    while (1) //infinite loop
    {
        scanf(" %c",&ch);
        switch (ch)
        {
        case 'a': //add at end
            scanf("%d", &info);
            insertAtEnd(&head, info);
            break;
        
        case 'b': //add at front
            scanf("%d", &info);
            insertAtBeginning(&head, info);
            break;
        
        case 'i'://insert at given index
            scanf("%d", &index);
            scanf("%d", &info);
            insertAt(head, info, index);
            break;

        case 'r': //remove first valu
            scanf("%d", &info);
            deleteFirstList(&head);
            break;

        case 'R': //reverse list
            reverseList(&head);
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
