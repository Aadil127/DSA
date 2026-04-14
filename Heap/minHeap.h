#ifndef __MIN_HEAP__H
#define __MIN_HEAP__H

typedef struct Heap Heap;

Heap *minHeapCreate(size_t size);

int minHeapEmpty(Heap *h);

size_t minHeapLength(Heap *h);

size_t minHeapSize(Heap *h);

int minHeapFull(Heap *h);

int minHeapTop(Heap *h);

void minHeapUp(Heap *h, int index);

void minHeapPush(Heap *h, int element);

int minHeapPop(Heap *h);

void minHeapPrint(Heap *h);

void minHeapRemove(Heap *h);

#endif
