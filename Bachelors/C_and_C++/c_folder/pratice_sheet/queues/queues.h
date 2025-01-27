#ifndef QUEUE_H
#define QUEUE_H

struct Queue {
    char item[20];
    int front;
};

void createQueue(struct Queue *newQueue);
void enqueue(struct Queue *newQueue, char newitem);
char dequeue(struct Queue *newQueue);
int isQueueEmpty(struct Queue *newQueue);
void freeQueue(struct Queue *newQueue);
void printQueue(struct Queue *newQueue);


#endif
