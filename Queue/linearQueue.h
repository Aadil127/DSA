#ifndef __linearQueue__H
#define __linearQueue__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Queue Queue;

Queue *lQueueCreate(size_t size, size_t elementSize);

int lQueueEmpty(Queue *q);

int lQueueFull(Queue *q);

int lEnqueue(Queue *q, void *element);

int lDequeue(Queue *q, void *element);

void lQueueRemove(Queue *q);

size_t lQueueSize(Queue *q);

size_t lQueueLen(Queue *q);

#endif
