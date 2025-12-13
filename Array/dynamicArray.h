#ifndef __dynamicArray__H
#define __dynamicArray__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
* Dynamic array
*/
typedef struct Array Array;

Array *arrayCreate(size_t size, size_t elementSize);

void arrayAppend(Array *a, void *element);

void arraySet(Array *a, void *element, size_t index);

int arrayEmpty(Array *a);

void arrayInsert(Array *a, void *element, size_t index);

void arrayDeleteElement(Array *a, size_t index);

void arrayRemove(Array *a);

void *arrayElement(Array *a, size_t index);

size_t arraySize(Array *a);

size_t arrayLength(Array *a);

#endif