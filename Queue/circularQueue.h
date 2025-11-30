#ifndef __circularQueue__H
#define __circularQueue__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Queue Queue;

Queue *queueCreate(size_t size, size_t elementSize);

int queueEmpty(Queue *q);

int queueFull(Queue *q);

void enqueue(Queue *q, void *element);

void dequeue(Queue *q, void *element);

void queueRemove(Queue *q);

#endif