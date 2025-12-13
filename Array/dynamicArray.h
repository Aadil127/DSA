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

int arrayEmpty(Array *a);

void arrayInsert(Array *a, void *element, int index);

void arrayDeleteElement(Array *a, int index);

void arrayRemove(Array *a);

void *arrayElement(Array *a, int index);

size_t arraySize(Array *a);

size_t arrayLength(Array *a);

#endif