#ifndef __DYNAMIC_ARRAY__H
#define __DYNAMIC_ARRAY__H

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

void *arrayElementR(Array *a, size_t index);

int arrayElement(Array *a, size_t index, void *element);

size_t arraySize(Array *a);

size_t arrayLength(Array *a);

int arrayShiftRight(Array *a, size_t steps, size_t index, size_t elementsAmount);

int arrayShiftLeft(Array *a, size_t steps, size_t index, size_t elementsAmount);

void arrayPrint(Array *a, void (*printElement)(void *element, size_t index));

int arrayRemoveE(Array *a, void (*deleteElement)(void *element));

int arrayClear(Array *a, void (*deleteElement)(void *element));

#endif
