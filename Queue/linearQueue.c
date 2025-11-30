#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linearQueue.h"

/*
* Linear queue
*/
struct Queue{
    void *queue;
    size_t elementSize, size, length;
    int front, rear;
};

//Creates queue of given size, datatype  and returns pointer of the queue
Queue *lQueueCreate(size_t size, size_t elementSize){
    Queue *q = malloc(sizeof(Queue));
    q->front = 0;
    q->size = size;
    q->rear = -1;
    q->length = 0;
    q->elementSize = elementSize;

    q->queue = malloc(size * elementSize);
    return q;
}

//Returns 1 if given queue is empty else 0
int lQueueEmpty(Queue *q){
    return q->length == 0;
}

//Returns 1 if given queue is full else 0
int lQueueFull(Queue *q){
    return q->length == q->size;
}

//Adds element to the queue
void lEnqueue(Queue *q, void *element){
    if(q->length == q->size){
        printf("Error : queue is full.");
        exit(1);
    }
    memcpy((char*)q->queue + q->rear * q->elementSize, element, q->elementSize);
    q->rear++;
    q->length++;
}

//Removes element form the queue
void lDequeue(Queue *q, void *element){
    if(q->length == 0){
        printf("Error : queue is empty.");
        exit(1);
    }
    memcpy(element, (char*)q->queue + (q->front - 1) * q->elementSize, q->elementSize);
    q->front++;
    q->length--;
}

//Frees the memory of a queue
void lQueueRemove(Queue *q){
    free(q->queue);
    free(q);
}

size_t lQueueSize(Queue *q){
    return q->size;
}

size_t lQueueLen(Queue *q){
    return q->length;
}