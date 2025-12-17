#include <stdio.h>
#include"dynamicArray.h"


int arrayLinearSearch(Array *a, int number);

int main(){
    Array *a = arrayCreate(1, sizeof(int));
    for (size_t i = 0; i < 20; i++){
        arrayAppend(a, &i);
    }

    int number = 10;
    printf("%d\n", arrayLinearSearch(a, number));

    arrayRemove(a);
    return 0;
}

int arrayLinearSearch(Array *a, int number){
    for (size_t index = 0; index < arrayLength(a); index++){
        if(number == *(int *)arrayElementR(a, index)){
            return index;
        }
    }
    return -1;
}