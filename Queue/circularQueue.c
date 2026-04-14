#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"circularQueue.h"

/*
* Circular queue
*/
struct Queue{
    void *queue;
    size_t elementSize, size,length;
    size_t front, rear;
};

//Creates queue of given size, datatype  and returns pointer of the queue
Queue *queueCreate(size_t size, size_t elementSize){
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
int queueEmpty(Queue *q){
    return q->length == 0;
}

//Returns 1 if given queue is full else 0
int queueFull(Queue *q){
    return q->length == q->size - 1;
}

//Adds element to the queue
int enqueue(Queue *q, void *element){
    if(queueFull(q)){
        return 1;
    }
    q->rear = (q->rear + 1) % q->size;
    q->length++;
    memcpy((char*)q->queue + q->rear * q->elementSize, element, q->elementSize);
    return 0;
}

//Removes element form the queue
int dequeue(Queue *q, void *element){
    if(queueEmpty(q)){
        return 1;
    }
    memcpy(element, (char*)q->queue + q->front * q->elementSize, q->elementSize);
    q->front = (q->front + 1) % q->size;
    q->length--;
    return 0;
}

//Frees the memory of a queue
void queueRemove(Queue *q){
    free(q->queue);
    free(q);
}

size_t queueSize(Queue *q){
    return q->size;
}

size_t queueLen(Queue *q){
    return q->length;
}

