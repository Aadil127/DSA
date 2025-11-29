#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "dynamicArray.h"

//Creates array of given size, datatype  and returns pointer of the array
Array *arrayCreate(size_t size, size_t elementSize){
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
        a->size *= 2;
        a->array = realloc(a->array, a->size * a->elementSize);
    }
    memcpy((char*)a->array + (a->length * a->elementSize), element, a->elementSize);
    a->length++;
}

//Returns 1 if given array is empty else 0
int arrayEmpty(Array *a){
    return a->length == 0;
}

//Inserts the element at given index in array
void arrayInsert(Array *a, void *element, int index){
    if(index >= a->size){
        a->size = index + 1;
        a->array = realloc(a->array, a->size * a->elementSize);
    }
    if(a->size <= a->length){
        a->size *= 2;
        a->array = realloc(a->array, a->size * a->elementSize);
    }
    if(a->length == 0){
        arrayAppend(a, element);
        return;
    }

    //shift all elements to right by 1 index
    if(index > a->length){
        printf("can not insert becaues given is bigger that array's length.");
        exit(1);
    }
    a->length++;
    memmove(
        (char *)a->array + (index + 1) * a->elementSize,
        (char *)a->array + index * a->elementSize,
        (a->length - index - 1) * a->elementSize
    );

    //copy element to give index of an array
    memcpy(
        (char *)a->array + index * a->elementSize,
        element,
        a->elementSize
    );
}


// Removes element at given index
void arrayDeleteElement(Array *a, int index){
    if(a->length == 0){
        printf("Error : Array is empty.");
        exit(1);
    }
    //shift all elements to left by 1 index
    memmove(
        (char *)a->array + index * a->elementSize,
        (char *)a->array + (index + 1) * a->elementSize,
        (a->length - index - 1) * a->elementSize
    );

    a->length--;
}

//Frees the memory of an array
void arrayRemove(Array *a){
    free(a->array);
    free(a);
}

int main(){
    int number = 100;
    Array *a = arrayCreate(1, sizeof(int));
    for(int i = 0; i < 10; i++){
        arrayInsert(a, &number, 0);
        // arrayAppend(a, &number);
        printf("Inserted %d at index 0\n", number);
        // arrayAppend(a, &number);
        number++;
    }

    printf("\nLength : %lu\n\n",a->length);

    int *numberptr;
    numberptr = (int *)a->array;
    for(int i = 0; i < a->length; i++){
        printf("Number : %d\n", *numberptr);
        numberptr++;
    }

    arrayRemove(a);

    return 0;
}