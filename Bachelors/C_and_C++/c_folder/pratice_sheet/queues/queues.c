#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queues.h"

int count = 0;

int isQueueEmpty(struct Queue *newQueue) {
    return newQueue->front == -1;
}

void createQueue(struct Queue *newQueue) {
    newQueue->front = -1;
}

void enqueue(struct Queue *newQueue, char newitem) {
    if (count < 20) {
        newQueue->item[count] = newitem;
        count++;
        newQueue->front = 0;  // Set front to 0 when the first item is enqueued
    } else {
        printf("Queue is full\n");
        exit(1);
    }
}

char dequeue(struct Queue *newQueue) {
    char itemRemoved;

    if (isQueueEmpty(newQueue)) {
        printf("Queue is empty\n");
        exit(1);
    }

    itemRemoved = newQueue->item[newQueue->front];

    // Shift remaining elements to fill the gap
    for (int i = 0; i < count - 1; i++) {
        newQueue->item[i] = newQueue->item[i + 1];
    }

    count--;

    // Update front to reflect the new front of the queue
    if (count == 0)
    {
        newQueue->front = -1;
    }
    else{
    newQueue->front = 0;
    }
    

    return itemRemoved;
}

void freeQueue(struct Queue *newQueue) {
    createQueue(newQueue); // Reset the queue
}

void printQueue(struct Queue *newQueue) {
    printf("Queue: \n");
    for (int i = 0; i < count; i++) {
        printf("%c ", newQueue->item[i]);
    }
    printf("\n");
}




