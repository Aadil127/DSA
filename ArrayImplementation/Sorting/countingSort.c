#include <stdio.h>
#include"dynamicArray.h"

int arrayMaxElement(Array *a);
void arrayCountingSort(Array *a);
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

    arrayCountingSort(a);

    printArray(a);

    arrayRemove(a);

    return 0;
}

int arrayMaxElement(Array *a){
    int max = 0;
    for(int i = 0; i < (int)arrayLength(a); i++){
        if(max < *(int *)arrayElementR(a, i)){
            max = *(int *)arrayElementR(a, i);
        }
    }
    return max;
}

void arrayCountingSort(Array *a){
    Array *count = arrayCreate( 1, sizeof(int));
    int zero = 0;
    int countArrayIndex = 0;
    int countArrayValueAtIndex = 0;
    for(int i = 0; i < arrayMaxElement(a) + 1; i++) arrayAppend(count, &zero); // setting all values of count array to 0
    
    for (int i = 0; i < (int)arrayLength(a); i++){ // counting elements in given array and setting values for count array
        countArrayIndex = *(int *)arrayElementR(a, i);
        countArrayValueAtIndex = *(int *)arrayElementR(count, countArrayIndex);
        countArrayValueAtIndex++;
        arraySet(count, &countArrayValueAtIndex, countArrayIndex);
    }
    
    countArrayIndex = 0;
    int mainIndex = 0;
    while(mainIndex < (int)arrayLength(a)){ // setting values in given array using count array
        countArrayValueAtIndex = *(int *)arrayElementR(count, countArrayIndex);
        if( countArrayValueAtIndex == 0){
            countArrayIndex++;
            countArrayValueAtIndex = *(int *)arrayElementR(count, countArrayIndex);
        }
        if(countArrayValueAtIndex > 0){
            arraySet(a, &countArrayIndex, mainIndex);
            // printf("\nvalue %d at index %d", *(int *)arrayElementR(a, mainIndex), mainIndex);
            countArrayValueAtIndex--;
            arraySet(count, &countArrayValueAtIndex, countArrayIndex);
        }
        mainIndex++;
    }
    arrayRemove(count);
}

void printArray(Array *a){
    printf("\n");
    for (int i = 0; i < (int)arrayLength(a); i++){
        printf("%d ", *(int *)arrayElementR(a, i));
    }
    printf("\n");
}