#ifndef __minHeap__H
#define __minHeap__H

typedef struct Heap Heap;

Heap *minHeapCreate(int size);

int minHeapEmpty(Heap *h);

int minHeapLength(Heap *h);

int minHeapSize(Heap *h);

int minHeapFull(Heap *h);

int minHeapTop(Heap *h);

void minHeapUp(Heap *h, int index);

void minHeapPush(Heap *h, int element);

int minHeapPop(Heap *h);

void minHeapPrint(Heap *h);

void minHeapRemove(Heap *h);

#endif