#include <stdio.h>
#include"dynamicArray.h"

void arrayBubbleSort(Array *a);
void printArray(Array *a);

int main(){
    // Initialization
    Array *a = arrayCreate(1, sizeof(int));

    int number = 2;
    arrayAppend(a, &number);
    number = 1;
    arrayAppend(a, &number);
    number = 3;
    arrayAppend(a, &number);
    number = 5;
    arrayAppend(a, &number);
    number = 4;
    arrayAppend(a, &number);
    number = 2;
    arrayAppend(a, &number);


    printArray(a);

    arrayBubbleSort(a);

    printArray(a);

    arrayRemove(a);

    return 0;
}

void arrayBubbleSort(Array *a){
    int valueSwapped = 0;
    for (int i = 0; i < (int)arrayLength(a) - 1 ; i++){
        valueSwapped = 0;
        for (int j = 0; j < (int)arrayLength(a) - i - 1; j++){
            if(*(int *)arrayElementR(a, j) > *(int *)arrayElementR(a, j + 1)){
                arraySwap(a, j, j + 1);
                valueSwapped = 1;
            }
        }
        if(valueSwapped == 0){
            break;
        }
    }

}

void printArray(Array *a){
    printf("\n");
    for (int i = 0; i < (int)arrayLength(a); i++){
        printf("%d ", *(int *)arrayElementR(a, i));
    }
    printf("\n");
}