#ifndef __dynamicSizeStack__H
#define __dynamicSizeStack__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack Stack;

Stack *stackCreate(int size, size_t elementSize);

int stackEmpty(Stack *s);

int stackFull(Stack *s);

int stackSize(Stack *s);

void stackPush(Stack *s, void *element);

void stackPop(Stack *s, void *element);

void stackPeek(Stack *s, void *element);

#endif