#ifndef __maxHeap__H
#define __maxHeap__H

typedef struct Heap Heap;

Heap *heapCreate(int size);

int heapEmpty(Heap *h);

int heapLength(Heap *h);

int heapSize(Heap *h);

int heapFull(Heap *h);

int heapTop(Heap *h);

void heapUp(Heap *h, int index);

void heapPush(Heap *h, int element);

int heapPop(Heap *h);

void heapPrint(Heap *h);

void heapRemove(Heap *h);

#endif