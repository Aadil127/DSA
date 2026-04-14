#ifndef __LINEAR_QUEUE__H
#define __LINEAR_QUEUE__H

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
