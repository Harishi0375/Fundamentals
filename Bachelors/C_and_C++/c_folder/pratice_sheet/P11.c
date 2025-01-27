#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
struct node {
    char str[20];
    struct node* next;
};

// Function to insert a new node at the beginning of the linked list
struct node* insertBegin(struct node* head, char str[]) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    strcpy(newNode->str, str);
    newNode->next = head;
    return newNode;
}

// Function to print the content of the linked list
void printList(struct node* head) {
    while (head != NULL) {
        printf("%s ", head->str);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct node* head) {
    while (head != NULL) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    char str[20];

    // Initialize the linked list
    struct node* head = NULL;

    // Read the number of strings
    scanf("%d", &n);

    // Read and insert strings into the linked list
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        head = insertBegin(head, str);
    }
    printList(head);
    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
