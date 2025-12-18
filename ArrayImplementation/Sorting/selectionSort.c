#include <stdio.h>
#include <dynamicArray.h>

void arraySelectionSort(Array *a);
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

    arraySelectionSort(a);

    printArray(a);

    arrayRemove(a);

    return 0;
}

void arraySelectionSort(Array *a){
    int minElementIndex;
    for (int i = 0; i < (int)arrayLength(a); i++){
        minElementIndex = i;
        for(int j = i + 1; j <  (int)arrayLength(a); j++){
            if( *(int *)arrayElementR(a, j) < *(int *)arrayElementR(a, minElementIndex)){
                minElementIndex = j;
            }
        }
        arraySwap(a, i,minElementIndex);
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