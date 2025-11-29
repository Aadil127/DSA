#ifndef __doublyLinkedList__H
#define __doublyLinkedList__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct DNode{
    void *element;
    struct DNode *next;
    struct DNode *prev;
} DNode;

typedef struct {
    size_t length, elementSize;
    DNode *head;
    DNode *tail;
} DList;

DList *dListCreate(size_t elementSize);

DNode *dListNodeCreate(DList *l, DNode *prev, void *element);

void dListAppend(DList *l, void *element);

void dListInsert(DList *l, void *element, int index);

void dListDeleteElement(DList *l, int index);

int dListLen(DList *l);

int dListEmpty(DList *l);

void dListTransverseFd(DList *l, void *element);

void dListTransverseBk(DList *l, void *element);

void dListRemove(DList *l);

#endif