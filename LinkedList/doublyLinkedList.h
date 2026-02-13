#ifndef __doublyLinkeList__H
#define __doublyLinkeList__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node Node;

typedef struct List List;

List *dListCreate(size_t elementSize);

Node *dListNodeCreate(List *l, Node *prev, void *element);

void dListAppend(List *l, void *element);

void dListInsert(List *l, void *element, int index);

void dListDeleteElement(List *l, int index);

size_t dListLen(List *l);

int dListEmpty(List *l);

void dListTransverseFd(List *l, void *element);

void *dListTransverseBkReturn(List *l);

void dListTransverseBk(List *l, void *element);

void *dListTransverseFdReturn(List *l);

void dListRemove(List *l);

#endif
