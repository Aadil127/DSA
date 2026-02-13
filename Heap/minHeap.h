#ifndef __minHeap__H
#define __minHeap__H

typedef struct Heap Heap;

Heap *minHeapCreate(size_t size);

int minHeapEmpty(Heap *h);

size_t minHeapLength(Heap *h);

size_t minHeapSize(Heap *h);

int minHeapFull(Heap *h);

int minHeapTop(Heap *h);

void minHeapUp(Heap *h, size_t index);

void minHeapPush(Heap *h, int element);

int minHeapPop(Heap *h);

void minHeapPrint(Heap *h);

void minHeapRemove(Heap *h);

#endif
