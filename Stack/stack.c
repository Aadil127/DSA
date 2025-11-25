#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//This checks the datatype of elememnt and calls fucntion related to that datatype at compile time
#define stackPush(s, element)\
    stackPushVoid(s,\
        _Generic((element),\
            int: &(int){element},\
            float: &(float){element},\
            double: &(double){element},\
            char: &(char){element}\
        )\
    )

#define stackTop(s)\
    _Generic((s)->type.i,\
        int*:   stackTopInt,\
        float*: stackTopFloat,\
        double*: stackTopDouble,\
        char*:  stackTopChar\
    )(s)


/*
* Fixed size stack
*/
typedef struct{
    void *stack;
    int top, size;
    size_t elementSize;
    /*
    * using union to get datatype for _Generic because union share memory for all the elements within it,
    * So _Generic((s)->type.i can access f,d or c    //Took so long to understand it :(        if you are reading it "Hello :)   o/ "
    */
    union{
        int   *i;
        float *f;
        double *d;
        char  *c;
    }type;
}Stack;


/*
* Creates stack of given size, datatype  and returns pointer of the stack
* Stack s = createStack(100, "int")
* or float, double, char
*/
Stack createStack(int size, char elementType[]){
    Stack s;
    s.top = -1;
    s.size = size;
    
    if(elementType == "int"){
        s.type.i = (int*)0;
        s.elementSize = sizeof(int);
    }
    else if (elementType == "float"){
        s.type.f = (float*)0;
        s.elementSize = sizeof(float);
    }
    else if (elementType == "double"){
        s.type.d = (double*)0;
        s.elementSize = sizeof(double);
    }
    else{
        s.type.c = (char*)0;
        s.elementSize = sizeof(char);
    }

    s.stack = malloc(size * s.elementSize);
    return s;
}

//Adds element on top of the stack
void stackPushVoid(Stack *s, void *element){
    if(s->top == s->size - 1) return;
    s->top++;
    memcpy((char*)s->stack + s->top * s->elementSize, element, s->elementSize);
}

//Removes the element from the top of the stack
void stackPop(Stack *s){
    if(s->top == -1) return;
    s->top--;
}

//Retruns the element from the top of the stack
int stackTopVoid(Stack *s, void *element){
    if(s->top == -1) return -1;
    memcpy(element, (char*)s->stack + s->top * s->elementSize, s->elementSize);
    return 0;
}
int stackTopInt(Stack *s){
    int element;
    if(!stackTopVoid(s, &element)) return element;
}
float stackTopFloat(Stack *s){
    float element;
    if(!stackTopVoid(s, &element)) return element;
}
double stackTopDouble(Stack *s){
    double element;
    if(!stackTopVoid(s, &element)) return element;
}
char stackTopChar(Stack *s){
    char element;
    printf("char");
    if(!stackTopVoid(s, &element)) return element;
}

//Frees the memory of the stack
void stackRemove(Stack *s){
    free(s->stack);
    free(s);
}

//Returns 1 if given stack is empty else 0
int stackEmpty(Stack *s){
    return s->top == -1;
}

//Returns 1 if given stack is full else 0
int StackFull(Stack *s){
    return s->top == s->size - 1;
}

//Returns the size of given stack
int stackSize(Stack *s){
    return s->top + 1;
}

int main(){
    Stack s = createStack(10, "int");//Initilizing stack with size 10;
    stackPush(&s, 100);
    stackPush(&s, 200);
    stackPop(&s);
    printf("%d\n", stackTop(&s));

    Stack s1 = createStack(5,"char");
    stackPush(&s1, 'A');
    stackPush(&s1, 'B');
    printf("%c\n", stackTop(&s1));

    stackRemove(&s);
    stackRemove(&s1);
    return 0;
}