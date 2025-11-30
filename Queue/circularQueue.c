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
    int front, rear;
};

//Creates queue of given size, datatype  and returns pointer of the queue
Queue *queueCreate(size_t size, size_t elementSize){
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
int queueEmpty(Queue *q){
    return q->length == 0;
}

//Returns 1 if given queue is full else 0
int queueFull(Queue *q){
    return q->length == q->size;
}

//Adds element to the queue
void enqueue(Queue *q, void *element){
    if(queueFull(q)){
        printf("Error : queue is full.");
        exit(1);
    }
    memcpy((char*)q->queue + q->rear * q->elementSize, element, q->elementSize);
    q->rear = (q->rear + 1) % q->size;
    q->length++;
}

//Removes element form the queue
void dequeue(Queue *q, void *element){
    if(queueEmpty(q)){
        printf("Error : queue is empty.");
        exit(1);
    }
    memcpy(element, (char*)q->queue + (q->front - 1) * q->elementSize, q->elementSize);
    // (q->front - 1) because we want to get previous element that front means dequeued element's value 
    q->front = (q->front + 1) % q->size;
    q->length--;
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

// int main(){

//     Queue *q = queueCreate(5, sizeof(int));
//     int number = 100;
//     enqueue(q, &number);
//     // 100
//     // rear = 0 front = 0

//     number = 200;
//     enqueue(q, &number);
//     // 100  200
//     // rear = 1 front = 0

//     number = 300;
//     enqueue(q, &number);
//     // 100  200  300
//     // rear = 2 front = 0


//     dequeue(q, &number);
//     printf("Number : %d\n", number);
//     // 100  200  300
//     // rear = 2 front = 1
    
//     dequeue(q, &number);
//     printf("Number : %d\n", number);
//     // 100  200  300
//     // rear = 2 front = 2

//     return 0;
// }