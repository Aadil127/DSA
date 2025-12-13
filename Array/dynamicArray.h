#ifndef __dynamicArray__H
#define __dynamicArray__H

#include<stddef.h>

/*
* Dynamic array
*/
typedef struct Array Array;

Array *arrayCreate(size_t size, size_t elementSize);

int arrayAppend(Array *a, void *element);

int arraySet(Array *a, void *element, size_t index);

int arraySwap(Array *a, size_t index1, size_t index2);

int arrayEmpty(Array *a);

int arrayInsert(Array *a, void *element, size_t index);

int arrayDeleteElement(Array *a, size_t index);

int arrayRemove(Array *a);

void *arrayElement(Array *a, size_t index);

size_t arraySize(Array *a);

size_t arrayLength(Array *a);

#endif