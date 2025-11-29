#ifndef __singlyLinkedList__H
#define __singlyLinkedList__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    void *element;
    struct Node *next;
} Node;

typedef struct {
    size_t length, elementSize;
    Node *head;
} List;

List *listCreate(size_t elementSize);

Node *listNodeCreate(List *l, void *element);

void listAppend(List *l, void *element);

void listInsert(List *l, void *element, int index);

void listDeleteElement(List *l, int index);

int listLen(List *l);

int listEmpty(List *l);

void dDListTransverseFd(List *l, void *element);

#endif