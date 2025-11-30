#ifndef __fixedSizeStack__H
#define __fixedSizeStack__H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack Stack;

Stack *fStackCreate(int size, size_t elementSize);

int fStackEmpty(Stack *s);

int fStackFull(Stack *s);

int fStackSize(Stack *s);

void fStackPush(Stack *s, void *element);

void fStackPop(Stack *s, void *element);

void fStackPeek(Stack *s, void *element);

#endif