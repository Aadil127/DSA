#ifndef __fixedSizeStack__H
#define __fixedSizeStack__H

#include<stddef.h>

typedef struct Stack Stack;

Stack *fStackCreate(int size, size_t elementSize);

int fStackEmpty(Stack *s);

int fStackFull(Stack *s);

int fStackSize(Stack *s);

int fStackPush(Stack *s, void *element);

int fStackPop(Stack *s, void *element);

int fStackPeek(Stack *s, void *element);

void fStackRemove(Stack *s);

#endif
