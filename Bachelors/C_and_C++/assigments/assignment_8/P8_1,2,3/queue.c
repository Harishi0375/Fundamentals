/**
 * @file queue.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
	return pq->items;
}

/**
 * Enqueues an item into the queue.
 *
 * @param item The item to be enqueued.
 * @param pq Pointer to the queue structure.
 * @return 1 if successful, 0 otherwise.
 */
int enqueue(Item item, Queue *pq) {
    // Allocate memory for the new node
    Node *new_node = (Node *)malloc(sizeof(Node));
    
    // Check if memory allocation is successful
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 0;
    }
    
    // Assign the item and initialize the next pointer
    new_node->item = item;
    new_node->next = NULL;

    // If the queue is empty, set both front and rear to the new node
    if (queue_is_empty(pq)) {
        pq->front = pq->rear = new_node;
    } else {
        // Otherwise, add the new node to the rear of the queue
        pq->rear->next = new_node;
        pq->rear = new_node;
    }
    
    // Increment the number of items in the queue
    pq->items++;
    
    return 1; // Enqueue operation successful
}

/**
 * Dequeues an item from the queue.
 *
 * @param pitem Pointer to store the dequeued item.
 * @param pq Pointer to the queue structure.
 * @return 1 if successful, 0 otherwise.
 */
int dequeue(Item *pitem, Queue *pq) {
    // Check if the queue is empty
    if (queue_is_empty(pq)) {
        fprintf(stderr, "Queue is empty!\n");
        return 0;
    }
    
    // Get the front node
    Node *temp = pq->front;
    
    // Retrieve the item to be dequeued
    *pitem = temp->item;
    
    // Move front to the next node
    pq->front = pq->front->next;
    
    // Free the dequeued node
    free(temp);
    
    // Decrement the number of items in the queue
    pq->items--;
    
    // If the queue becomes empty, update the rear pointer
    if (queue_is_empty(pq)) {
        pq->rear = NULL;
    }
    
    return 1; // Dequeue operation successful
}

/**
 * Prints the items in the queue.
 *
 * @param pq Pointer to the queue structure.
 */
void print_queue(const Queue *pq) {
    // Check if the queue is empty
    // if (queue_is_empty(pq)) {
    //     printf("Queue is empty.\n");
    //     return;
    // }

    // Temporary pointer to iterate through the queue
    Node *current = pq->front;

    // Print each item in the queue
    printf("content of the queue: ");
    while (current != NULL) {
        // Assuming Item is int, modify the format specifier based on your data type
        printf("%d ", current->item); // Modify the format specifier for your data type
        current = current->next;
    }
    printf("\n");
}


void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq)) {
		dequeue(&dummy, pq);
	}
}