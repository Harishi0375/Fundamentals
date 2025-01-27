/*
CH-230-A
a7_p1.c
Harishi Velavan
hvelavan@jacobs-university.de
*/

// use_linked_list.c

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    char ch;
    int info;
    struct List* head = NULL;

    while (1) {
        scanf(" %c", &ch);
        switch (ch) {
            case 'a':
                scanf("%d", &info);
                insertAtEnd(&head, info);
                break;
        
            case 'b':
                scanf("%d", &info);
                insertAtBeginning(&head, info);
                break;

            case 'r':
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
    
    return 0;
}
