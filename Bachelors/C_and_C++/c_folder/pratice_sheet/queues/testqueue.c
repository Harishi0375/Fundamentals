#include "queues.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct Queue *newQueue = malloc(sizeof(struct Queue));

    createQueue(newQueue);
    printf("Enqueueing items:\n");
    enqueue(newQueue, 'A');
    enqueue(newQueue, 'B');
    enqueue(newQueue, 'C');
    printQueue(newQueue);

    printf("Dequeueing an item: %c\n", dequeue(newQueue));
    printQueue(newQueue);

    printf("Dequeueing an item: %c\n", dequeue(newQueue));
    printQueue(newQueue);

    
    printf("Freeing the queue\n");
    freeQueue(newQueue);

    free(newQueue);

    return 0;
}
