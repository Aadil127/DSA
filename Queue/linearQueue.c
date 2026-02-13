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
    size_t front, rear;
};

//Creates queue of given size, datatype  and returns pointer of the queue
Queue *lQueueCreate(size_t size, size_t elementSize){
    Queue *q = malloc(sizeof(Queue));
    q->front = 0;
    q->size = size;
    q->rear = 0;
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
    return q->length == q->size - 1;
}

//Adds element to the queue
int lEnqueue(Queue *q, void *element){
    if(q->length == q->size){
        return 1;
    }
    q->rear++;
    q->length++;
    memcpy((char*)q->queue + q->rear * q->elementSize, element, q->elementSize);
    return 0;
}

//Removes element form the queue
int lDequeue(Queue *q, void *element){
    if(q->length == 0){
        return 1;
    }
    memcpy(element, (char*)q->queue + q->front * q->elementSize, q->elementSize);
    q->front++;
    q->length--;
    return 0;
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
