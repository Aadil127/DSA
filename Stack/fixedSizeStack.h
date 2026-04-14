#ifndef __FIXED_SIZE_SATCK__H
#define __FIXED_SIZE_SATCK__H

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
