#include <stdio.h>
#include"dynamicArray.h"

int arrayBinarySearch(Array *a, int number);

int main(){
    // Initialization
    Array *a = arrayCreate(1, sizeof(int));
    for (int i = 10; i < 60; i++){
        arrayAppend(a, &i);
    }

    // Binary search
    printf("Using loop.\n");
    for (int number = 0; number < (int)arrayLength(a); number++){
        printf("%d\n", arrayBinarySearch(a, number));
    }

    arrayRemove(a);
    
    return 0;
}


int arrayBinarySearch(Array *a, int number){
    int low = 0;
    int high = arrayLength(a) - 1;
    int mid = 0;
    while(low <= high){
        mid = low + (high - low) / 2;
        
        if(number ==  *(int *)arrayElementR(a, mid)){
            return mid;
        }
        else if(number > *(int *)arrayElementR(a, mid)){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}