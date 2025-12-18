#include<stdlib.h>
#include<string.h>
#include "dynamicArray.h"

struct Array{
    void *array;
    size_t elementSize, size, length;
};

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
int arrayAppend(Array *a, void *element){
    if(a->size <= a->length){
        a->size *= 2;
        a->array = realloc(a->array, a->size * a->elementSize);
    }
    memcpy((char*)a->array + (a->length * a->elementSize), element, a->elementSize);
    a->length++;
    return 0;
}

// Sets element at given index in array
int arraySet(Array *a, void *element, size_t index){
    if(index > a->length){
        return -1;
    }
    memcpy((char*)a->array + (index * a->elementSize), element, a->elementSize);
    return 0;
}

// Swap two emements
int arraySwap(Array *a, size_t index1, size_t index2){
    if(index1 >= a->length || index2 >= a->length) return -1;
    void *temp = malloc(a->elementSize);
    memcpy(temp, (char *)a->array + (index1 * a->elementSize), a->elementSize);
    memcpy((char *)a->array + (index1 * a->elementSize), (char *)a->array + (index2 * a->elementSize), a->elementSize);
    memcpy((char *)a->array + (index2 * a->elementSize), temp, a->elementSize);
    free(temp);
    return 0;
}

//Returns 1 if given array is empty else 0
int arrayEmpty(Array *a){
    return a->length == 0;
}

//Inserts the element at given index in array
int arrayInsert(Array *a, void *element, size_t index){
    if(index > a->length){
        return -1;
    }
    if(a->size <= a->length){
        a->size *= 2;
        a->array = realloc(a->array, a->size * a->elementSize);
    }
    if(a->length == 0){
        arrayAppend(a, element);
        return 0;
    }

    //shift all elements to right by 1 index
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
    return 0;
}


// Removes element at given index
int arrayDeleteElement(Array *a, size_t index){
    if(a->length == 0 || index >= a->length){
        return -1;
    }
    //shift all elements to left by 1 index
    memmove(
        (char *)a->array + index * a->elementSize,
        (char *)a->array + (index + 1) * a->elementSize,
        (a->length - index - 1) * a->elementSize
    );

    a->length--;
    return 0;
}

//Frees the memory of an array
int arrayRemove(Array *a){
    free(a->array);
    free(a);
    return 0;
}

// Direclty returns pointer to element for given index, will return NULL if index in out of bounds for given array
void *arrayElementR(Array *a, size_t index){
    if(index >= a->length) return NULL;
    return (char *)a->array + index * a->elementSize;
}

// Copy contents of element at given index to given address
int arrayElement(Array *a, size_t index, void *element){
    memcpy(element, (char *)a->array + index * a->elementSize, a->elementSize);
    return 0;
}

// Returns total size of an array
size_t arraySize(Array *a){
    return a->size;
}

// Returns current size of an array that elements are using
size_t arrayLength(Array *a){
    return a->length;
}

// Shifts array's elements of given amount by specified steps to right starting frome given index
// stpes = 1, index = 1, elementsAmount = 2 shifts 2 elements of array to right by one index form index 1
// [1, 2, 3, 4, 5, 6, 7] -> [1, _, 2, 3, 5, 6, 7]
// stpes = 2, index = 1, elementsAmount = 2 shifts 2 elements of array to right by two indexes form index 1
// [1, 2, 3, 4, 5, 6, 7] -> [1, _, _, 2, 3, 6, 7]
int arrayShiftRight(Array *a, size_t steps, size_t index, size_t elementsAmount){
    if(!a || a->length == 0 || index > a->length){
        return -1;
    }
    if(steps == 0){
        return 0;
    }
    memmove(
        (char *)a->array + (index + steps) * a->elementSize,
        (char *)a->array + index * a->elementSize,
        (elementsAmount - steps) * a->elementSize
    );
    return 0;
}

// Shifts array's elements of given amount by specified steps to left starting frome given index
// stpes = 1, index = 1, elementsAmount = 2 shifts 2 elements of array to left by one index form index 1
// [1, 2, 3, 4, 5, 6, 7] -> [2, 3, _, 4, 5, 6, 7]
// stpes = 2, index = 1, elementsAmount = 2 shifts 2 elements of array to left by two indexes form index 1
// [1, 2, 3, 4, 5, 6, 7] -> [3, _, _, 4, 5, 6, 7]
int arrayShiftLeft(Array *a, size_t steps, size_t index, size_t elementsAmount){
    if(!a || a->length == 0 || index > a->length){
        return -1;
    }
    if(steps == 0){
        return 0;
    }
    memmove(
        (char *)a->array + index * a->elementSize,
        (char *)a->array + (index + steps) * a->elementSize,
        (elementsAmount - steps) * a->elementSize
    );
    return 0;
}