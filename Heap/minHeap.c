#include<stdio.h>
#include<stdlib.h>
#include"minHeap.h"

/*
* Min Heap
*/
struct Heap{
    int *array;
    size_t length, size;
};

// Creates heap with given size and returns pointer
Heap *minHeapCreate(size_t size){
    Heap *h = malloc(sizeof(Heap));
    h->size = size; // total size of heap
    h->length = 0; // current space taken by elements
    h->array = malloc(size * sizeof(int));
    return h;
}

// returns true(1) if heap is empty else false(0)
int minHeapEmpty(Heap *h){
    return h->length == 0;
}

// returns heap's total size
size_t minHeapSize(Heap *h){
    return h->size;
}

// returns heap's length(filled elements)
size_t minHeapLength(Heap *h){
    return h->length;
}

// returns true(1) if heap is full else false(0)
int minHeapFull(Heap *h){
    return h->length == h->size;
}

// returns root element
int minHeapTop(Heap *h){
    return h->array[0];
}

// uitlity funstion to swap variable
void minHeapSwap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// moves element up in heap
void minHeapUp(Heap *h, size_t index){
    int *array = h->array;
    while(index >= 0 && array[(index - 1 )/ 2] > array[index]){
        minHeapSwap(&array[(index - 1 )/ 2], &array[index]);
        index = (index - 1) / 2;
    }
}

// moves element down in heap
void minHeapDown(Heap *h){
    int *array = h->array;
    size_t index = 0;

    size_t smallChildIndex = (array[index * 2 + 1] < array[index *2 + 2]) ? index * 2 + 1 : index * 2 + 2;
    while(index <= h->length && array[index] > array[smallChildIndex]){
        minHeapSwap(&array[index], &array[smallChildIndex]);
        index = smallChildIndex;
    }
}

// adds new element in heap
void minHeapPush(Heap *h, int element){
    if(h->length == h->size){
        h->array = realloc(h->array, h->size * 2);
    }
    h->array[h->length] = element;
    size_t index = h->length;
    minHeapUp(h, index);
    h->length++;
}

// removes root emement from heap and returns it
int minHeapPop(Heap *h){
    int rootElement = h->array[0];
    h->array[0] = h->array[h->length - 1];
    h->length--;
    minHeapDown(h);
    return rootElement;
}

// prints elements of heap
void minHeapPrint(Heap *h){
    int *array = h->array;
    printf("Heap value.\n");
    for(size_t index = 0; index < h->length; index++){
        printf("%d ", array[index]);
    }
    printf("\n");
}

//Frees the memory of a heap
void minHeapRemove(Heap *h){
    free(h->array);
    free(h);
}

// int main(){
//     // min Heap
//     Heap *h1 = minHeapCreate(100);

//     minHeapPush(h1, 10);
//     minHeapPush(h1, 9);
//     minHeapPush(h1, 8);
//     minHeapPush(h1, 3);
//     minHeapPush(h1, 20);

//     minHeapPrint(h1);

//     minHeapPop(h1);

//     minHeapPrint(h1);

//     minHeapRemove(h1);

//     return 0;
// }
