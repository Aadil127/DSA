#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fixedSizeStack.h"

/*
* Fixed size stack
*/
struct Stack{
    void *stack;
    int top,size;
    size_t elementSize;
};

//Creates stack of given size, datatype  and returns pointer of the stack
Stack *fStackCreate(int size, size_t elementSize){
    Stack *s = malloc(sizeof(Stack));
    s->top = -1;
    s->size = size;
    s->elementSize = elementSize;
    s->stack = malloc(size * elementSize);
    return s;
}

//Returns 1 if given stack is empty else 0
int fStackEmpty(Stack *s){
    return s->top == -1;
}

//Returns 1 if given stack is full else 0
int fStackFull(Stack *s){
    return s->top == s->size - 1;
}

//Returns the size of given stack
int fstackSize(Stack *s){
    return s->top + 1;
}

//Adds element on top of the stack
void fStackPush(Stack *s, void *element){
    if(s->top == s->size - 1){
        printf("Error : Stack is full");
        exit(1);
    }
    s->top++;
    memcpy((char*)s->stack + s->top * s->elementSize, element, s->elementSize);
}

/*
* Removes the element from the top of the stack and returns it to given pointer
* int number;
* stackPop(s, &number);
* Returns the value from top of the stack to number variable
*/
void fStackPop(Stack *s, void *element){
    if(s->top == -1){
        printf("Error : Stack is empty");
        exit(1);
    }
    memcpy(element, (char*)s->stack + s->top * s->elementSize, s->elementSize);
    s->top--;
}

/*
* Returns element from the top of the stack to given pointer
* int number;
* stackPeek(s, &number);
* Returns the value from top of the stack to number variable
*/
void fStackPeek(Stack *s, void *element){
    if(s->top == -1){
        printf("Error : Stack is empty");
        exit(1);
    }
    memcpy(element, (char*)s->stack + s->top * s->elementSize, s->elementSize);
}

int fStackSize(Stack *s){
    return s->top + 1;
}

//Frees the memory of the stack
void fStackRemove(Stack *s){
    free(s->stack);
    free(s);
}

// int main(){
//     Stack *s = stackCreate(10, sizeof(int));//Initilizing stack with size 10;
//     int number = 100;
//     stackPush(s, &number);
//     number = 200;
//     stackPush(s, &number);
//     stackPop(s, &number);

//     Stack *s1 = stackCreate(5,sizeof(char));
//     char c = 'A';
//     stackPush(s1, &c);
//     c = 'B';
//     stackPush(s1, &c);

//     stackRemove(s);
//     stackRemove(s1);
//     return 0;
// }