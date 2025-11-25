#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
* Dynamic array
*/
typedef struct {
    void *array;
    size_t elementSize, size, length;
}Array;

//Creates array of given size, datatype  and returns pointer of the array
Array *arrayCreate(int size, size_t elementSize){
    Array *a = malloc(sizeof(Array));
    a->length = 0;
    a->size = size;
    a->elementSize = elementSize;
    a->array = malloc(size * elementSize);
    return a;
}

//Appends the element at the end of an array
void arrayAppend(Array *a, void *element){
    if(a->size == a->length){
        a->size *=2;
        a->array = realloc(a->array, a->size * a->elementSize);
    }
    memcpy((char*)a->array + a->length * a->elementSize, element, a->elementSize);
    a->length++;
}

//Inserts the element at given index in array
void arrayInsert(Array *a, void *element, int index){
    if(a->size == a->length){
        a->size *=2;
        a->array = realloc(a->array, a->size * a->elementSize);
    }
    // memcpy((char*)a->array + a->length * a->elementSize, element, a->elementSize);
    // a->length++;

    //shift all elements to right by 1 index
    memmove(
        (char *)a->array + (index + 1) * a->elementSize,
        (char *)a->array + index * a->elementSize,
        (a->length - index) * a->elementSize
    );

    //copy element to give index of an array
    memcpy(
        (char *)a->array + (index) * a->elementSize,
        element,
        a->elementSize
    );

    a->length++;
}

//Frees the memory of an array
void arrayRemove(Array *a){
    free(a->array);
    free(a);
}

int main(){
    Array *a = arrayCreate(2, sizeof(int));
    int number = 100;
    for(int i = 0; i < 10; i++){
        arrayInsert(a, &number, 0);
        // arrayAppend(a, &number);
        arrayAppend(a, &number);
        number++;
    }

    int *numberptr;
    for(int i = 0; i < a->length; i++){
        numberptr = (int *)((char *)a->array + i * a->elementSize);
        printf("Number : %d\n", *numberptr);
    }
    int *numberptr2 = (int *)(a->array);
    printf("Number test. : %d\n", *(numberptr2 + a->length - 1));
    printf("Number test. : %d\n", numberptr2[0]);

    arrayRemove(a);
    return 0;
}