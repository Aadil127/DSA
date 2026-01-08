#include <stdio.h>
#include "dynamicArray.h"

void arrayInsertionSort(Array *a);
void printArray(Array *a);

int main(){
    // Initialization
    Array *a = arrayCreate(1, sizeof(int));

    int number = 1;
    arrayAppend(a, &number);
    number = 2;
    arrayAppend(a, &number);
    number = 10;
    arrayAppend(a, &number);
    number = 0;
    arrayAppend(a, &number);
    number = 3;
    arrayAppend(a, &number);
    number = 2;
    arrayAppend(a, &number);


    printArray(a);

    arrayInsertionSort(a);

    printArray(a);

    arrayRemove(a);

    return 0;
}

void arrayInsertionSort(Array *a){
    int swapIndex = 0;
    for (int i = 1; i < (int)arrayLength(a); i++){
        // printf("main array\n");
        // printf("%d", i);
        // printArray(a);


        if(*(int *)arrayElementR(a, i - 1) > *(int *)arrayElementR(a, i)){
            // printf("starting sub loop\n");
            swapIndex = 0;
            for(int j = i - 1; j > -1; j--){

                if(*(int *)arrayElementR(a, i) > *(int *)arrayElementR(a, j) || j == 0){
                    
                    if(j == 0) swapIndex = 0;
                    else swapIndex = j + 1;

                    int swapValue = *(int *)arrayElementR(a, i);
                    arrayShiftRight(a, 1, swapIndex, i - swapIndex);
                    arraySet(a, &swapValue, swapIndex);
                    break;
                }
            }
        }
    }
}

// utility fucntion to print array
void printArray(Array *a){
    printf("\n");
    for (int i = 0; i < (int)arrayLength(a); i++){
        printf("%d ", *(int *)arrayElementR(a, i));
    }
    printf("\n");
}