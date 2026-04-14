#ifndef __DYNAMIC_SIZE_SATCK__H
#define __DYNAMIC_SIZE_SATCK__H

typedef struct Stack Stack;

Stack *stackCreate(size_t elementSize);

int stackEmpty(Stack *s);

int stackFull(Stack *s);

int stackSize(Stack *s);

void stackPush(Stack *s, void *element);

int stackPop(Stack *s, void *element);

int stackPeek(Stack *s, void *element);

void stackRemove(Stack *s);

#endif
