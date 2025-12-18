#include <stdio.h>
#include"dynamicArray.h"

int arrayMaxElement(Array *a);
void arrayRadixSort(Array *a);
void printArray(Array *a);

int main(){
    // Initialization
    Array *a = arrayCreate(1, sizeof(int));

    int number = 22;
    arrayAppend(a, &number);
    number = 12;
    arrayAppend(a, &number);
    number = 34;
    arrayAppend(a, &number);
    number = 15;
    arrayAppend(a, &number);
    number = 444;
    arrayAppend(a, &number);
    number = 2;
    arrayAppend(a, &number);

    printArray(a);

    arrayRadixSort(a);

    printArray(a);

    arrayRemove(a);

    return 0;
}

// returns max element of an array
int arrayMaxElement(Array *a){
    int max = 0;
    for(int i = 0; i < (int)arrayLength(a); i++){
        if(max < *(int *)arrayElementR(a, i)){
            max = *(int *)arrayElementR(a, i);
        }
    }
    return max;
}


// utility fucntion to print array
void printArray(Array *a){
    printf("\n");
    for(int i = 0; i < (int)arrayLength(a); i++){
        printf("%d ", *(int *)arrayElementR(a, i));
    }
    printf("\n");
}

void arrayRadixSort(Array *a){
    int maxValue = arrayMaxElement(a);
    int exponent = 1;
    int element;
    int radixArrayIndex;

    Array *radixArray = arrayCreate(10, sizeof(Array *));
    Array *row;
    for(int i = 0; i < 10; i++){
        row = arrayCreate(1, sizeof(int));
        arrayAppend(radixArray, &row);
        // printf("radix array row %d address %p\n", i, *(Array **)arrayElementR(radixArray, i));
    }

    while(maxValue / exponent > 0){
        // printf("\nExponent %d\n", exponent);
        for(int i = 0; i < (int)arrayLength(a); i++){
            element = *(int *)arrayElementR(a, i);

            // printf("Element %d\n", element);

            radixArrayIndex = (element / exponent) % 10;
            // printf("Element index %d\n", radixArrayIndex);

            row = *(Array **)arrayElementR(radixArray, radixArrayIndex);
            arrayAppend(row, &element);
        }

        int mainArrayIndex = 0;
        for(int i = 0; i < (int)arrayLength(radixArray); i++){

            row = *(Array **)arrayElementR(radixArray, i);
            for(int j = 0; j < (int)arrayLength(row); j++){

                element = *(int *)arrayElementR(row, j);
                arraySet(a, &element, mainArrayIndex);
                mainArrayIndex++;
            }

            // Remving all of the elements of row 
            arrayRemove(row);
            row = arrayCreate(1, sizeof(int));
            arraySet(radixArray, &row, i);
        }

        exponent *= 10;
    }

    //frees memory of radix array
    for(int i = 0; i < (int)arrayLength(radixArray); i++){
        row = *( Array**)arrayElementR(radixArray, i);
        arrayRemove(row);
    }
    arrayRemove(radixArray);
}
