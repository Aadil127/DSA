#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dynamicSizeStack.h"

/*
* Dynamic stack
*/
struct Stack{
    void *stack;
    int top,size;
    size_t elementSize;
};

//Creates stack of given size, datatype  and returns pointer of the stack
Stack *stackCreate(size_t elementSize){
    Stack *s = malloc(sizeof(Stack));
    s->top = -1;
    s->size = 1;
    s->elementSize = elementSize;
    s->stack = malloc(elementSize);
    return s;
}

//Returns 1 if given stack is empty else 0
int stackEmpty(Stack *s){
    return s->top == -1;
}

//Returns 1 if given stack is full else 0
int stackFull(Stack *s){
    return s->top == s->size - 1;
}

//Returns the size of given stack
int stackSize(Stack *s){
    return s->top + 1;
}

//Adds element on top of the stack
void stackPush(Stack *s, void *element){
    if(stackFull(s)){
        s->size *= 2;
        s->stack = realloc(s->stack, (size_t)s->size * s->elementSize);
    }
    s->top++;
    memcpy((char*)s->stack + (size_t)s->top * s->elementSize, element, s->elementSize);
}

/*
* Removes the element from the top of the stack and returns it to given pointer
* int number;
* stackPop(s, &number);
* Returns the value from top of the stack to number variable
*/
int stackPop(Stack *s, void *element){
    if(stackEmpty(s)){
        return 1;
    }
    memcpy(element, (char*)s->stack + (size_t)s->top * s->elementSize, s->elementSize);
    s->top--;
    return 0;
}

/*
* Returns element from the top of the stack to given pointer
* int number;
* stackPeek(s, &number);
* Returns the value from top of the stack to number variable
*/
int stackPeek(Stack *s, void *element){
    if(stackEmpty(s)){
        return 1;
    }
    memcpy(element, (char*)s->stack + (size_t)s->top * s->elementSize, s->elementSize);
    return 0;
}

//Frees the memory of a stack
void stackRemove(Stack *s){
    free(s->stack);
    free(s);
}
