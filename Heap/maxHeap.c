#include<stdio.h>
#include<stdlib.h>
#include"maxHeap.h"

/*
* Max Heap
*/
struct Heap{
    int *array;
    size_t length, size;
};

// Creates heap with given size and returns pointer
Heap *heapCreate(size_t size){
    Heap *h = malloc(sizeof(Heap));
    h->size = size; // total size of heap
    h->length = 0; // current space taken by elements
    h->array = malloc(size * sizeof(int));
    return h;
}

// returns true(1) if heap is empty else false(0)
int heapEmpty(Heap *h){
    return h->length == 0;
}

// returns heap's total size
size_t heapSize(Heap *h){
    return h->size;
}

// returns heap's length(filled elements)
size_t heapLength(Heap *h){
    return h->length;
}

// returns true(1) if heap is full else false(0)
int heapFull(Heap *h){
    return h->length == h->size;
}

// returns root element
int heapTop(Heap *h){
    return h->array[0];
}

// uitlity funstion to swap variable
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// moves element up in heap
void heapUp(Heap *h, int index){
    int *array = h->array;
    while(index >= 0 && array[(index - 1 )/ 2] < array[index]){
        swap(&array[(index - 1 )/ 2], &array[index]);
        index = (index - 1) / 2;
    }
}

// moves element down in heap
void heapDown(Heap *h){
    int *array = h->array;
    size_t index = 0;

    size_t largeChildIndex = (array[index * 2 + 1] > array[index *2 + 2]) ? index * 2 + 1 : index * 2 + 2;
    while(index <= h->length && array[index] < array[largeChildIndex]){
        swap(&array[index], &array[largeChildIndex]);
        index = largeChildIndex;
    }
}

// adds new element in heap
void heapPush(Heap *h, int element){
    if(h->length == h->size){
        h->array = realloc(h->array, h->size * 2);
    }
    h->array[h->length] = element;
    int index = (int)h->length;
    heapUp(h, index);
    h->length++;
}

// removes root emement from heap and returns it
int heapPop(Heap *h){
    int rootElement = h->array[0];
    h->array[0] = h->array[h->length - 1];
    h->length--;
    heapDown(h);
    return rootElement;
}

// prints elements of heap
void heapPrint(Heap *h){
    int *array = h->array;
    printf("Heap value.\n");
    for(size_t index = 0; index < h->length; index++){
        printf("%d ", array[index]);
    }
    printf("\n");
}

//Frees the memory of a heap
void heapRemove(Heap *h){
    free(h->array);
    free(h);
}

// int main(){
//     //Heap
//     Heap *h = heapCreate(100);

//     heapPush(h, 10);
//     heapPush(h, 9);
//     heapPush(h, 8);
//     heapPush(h, 3);
//     heapPush(h, 20);

//     heapPrint(h);

//     heapPop(h);

//     heapPrint(h);

//     heapRemove(h);

//     return 0;
// }
