#ifndef __maxHeap__H
#define __maxHeap__H

typedef struct Heap Heap;

Heap *heapCreate(size_t size);

int heapEmpty(Heap *h);

size_t heapLength(Heap *h);

size_t heapSize(Heap *h);

int heapFull(Heap *h);

int heapTop(Heap *h);

void heapUp(Heap *h, size_t index);

void heapPush(Heap *h, int element);

int heapPop(Heap *h);

void heapPrint(Heap *h);

void heapRemove(Heap *h);

#endif
