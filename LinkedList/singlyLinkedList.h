#ifndef __singlyLinkedList__H
#define __singlyLinkedList__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node Node;

typedef struct List List;

List *listCreate(size_t elementSize);

Node *listNodeCreate(List *l, void *element);

void listAppend(List *l, void *element);

void listInsert(List *l, void *element, int index);

void listDeleteElement(List *l, int index);

int listLen(List *l);

int listEmpty(List *l);

void listTransverseFd(List *l, void *element);

void *listTransverseFdReturn(List *l);

void listRemove(List *l);

#endif