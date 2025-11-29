#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"doublyLinkedList.h"

// Creates Doubly Linked List and returns pointer of the list
DList *dListCreate(size_t elementSize){
    DList *l = calloc(1, sizeof(DList));
    l->head = calloc(1, sizeof(DNode));
    l->tail = calloc(1, sizeof(DNode));
    l->length = 0;
    l->elementSize = elementSize;
    return l;
}

// Creates node of the Doubly Linked List and returns pointer of that node
DNode *dListNodeCreate(DList *l, DNode *prev, void *element){
    DNode *newDNode = malloc(sizeof(DNode));
    newDNode->element = malloc(l->elementSize);
    memcpy(newDNode->element, element, l->elementSize);
    newDNode->prev = prev;
    newDNode->next = NULL;
    return newDNode;
}

// Adds element at the end of the DList
void dListAppend(DList *l, void *element){
    if(l->length == 0){
        l->head = dListNodeCreate(l, NULL, element);
    }
    else{
        DNode *currentDNode = l->head;
        while (currentDNode->next){
            currentDNode = currentDNode->next;
        }
        currentDNode->next = dListNodeCreate(l, currentDNode, element);
        l->tail = currentDNode->next;
    }
    l->length++;
}

// Adds element at given index
void dListInsert(DList *l, void *element, int index){
    if(index > l->length){
        printf("\nCan not access index that is outside of a DList\n");
        return;
    }
    // Inserting element in front of a DList
    if(index == 0){

        if(l->length > 0){
            DNode *newDNode = malloc(sizeof(DNode));
            newDNode->element = malloc(l->elementSize);
            memcpy(newDNode->element, element, l->elementSize);
            newDNode->next = l->head;
            newDNode->prev = NULL;
            l->head = newDNode;
        }
        else{
            //if DList is empty
            l->head = dListNodeCreate(l, NULL, element);
        }
    }
    else{
        //For adding element in the middle of a DList
        int currentIndex = 0;
        DNode *currentDNode = l->head;
        while (currentDNode->next){
            if(currentIndex == index - 1) break;
            currentDNode = currentDNode->next;
            currentIndex++;
        }
        DNode *newDNode = malloc(sizeof(DNode));
        newDNode->element = malloc(l->elementSize);
        memcpy(newDNode->element, element, l->elementSize);
        newDNode->prev = currentDNode;
        newDNode->next = currentDNode->next;
        currentDNode->next = newDNode;
        l->tail = newDNode;
    }
    l->length++;
}


// Removes element of a list at given index
void dListDeleteElement(DList *l, int index){
    if(index == 0){
        // Removes old head Dnode and makes pointer of the DList point to next Dnode
        DNode *oldHead = l->head;
        l->head = l->head->next;
        free(oldHead->element);
        free(oldHead);
    }
    else if(index == l->length - 1){
        DNode *currentDNode = l->head;
        int currentIndex = 0;
        while (currentDNode->next && currentIndex < index - 1){
            currentDNode = currentDNode->next;
            currentIndex++;
        }
        free(currentDNode->next->element);
        free(currentDNode->next);
        currentDNode->next = NULL;
    }
    else{
        DNode *Dnode = l->head;
        int currentIndex = 0;
        while (Dnode->next){
            if(currentIndex == index - 1) break;
            Dnode = Dnode->next;
            currentIndex++;
        }
        DNode *tempDNode = Dnode->next;
        Dnode->next = tempDNode->next;
        free(tempDNode->element);
        free(tempDNode);
    }
    l->length--;
}


// Returns length of given list
int dListLen(DList *l){//Not really need can directly access it.
    return l->length;
}

// Returns 1 if list in empty else 0
int dListEmpty(DList *l){
    return l->length == 0;
}

// Moves to next node in each function call starting from head and retruns element of each node
void dListTransverseFd(DList *l, void *element){
    if(DListEmpty(l)){
        printf("List in empty.");
        exit(1);
    }
    static DNode *n = NULL;
    if(n == NULL){
        n = malloc(sizeof(DNode));
        n = l->head;
    }
    else{
        n = n->next;
    }
    memcpy(element, n->element, l->elementSize);
}

// Moves to previous node in each function call starting from tail and retruns element of each node
void dListTransverseBK(DList *l, void *element){
    if(DListEmpty(l)){
        printf("List in empty.");
        exit(1);
    }
    static DNode *n = NULL;
    if(n == NULL){
        n = malloc(sizeof(DNode));
        n = l->tail;
    }
    else{
        n = n->prev;
    }
    memcpy(element, n->element, l->elementSize);
}


void dListPrint(DList *l){
    DNode *n = l->head;
    int index = 0;
    while (n->next){
        printf("index : %d Value %d\n", index, *(int *)n->element);
        n = n->next;
        index++;
    }
    printf("index : %d Value %d\n", index, *(int *)n->element);
}


int main(){
    // DList *l = dDListCreate(sizeof(int));
    // int number = 100;
    // for(int i = 0; i < 10; i++){
    //     dDListAppend(l, &number);
    //     number += 100;
    // }
    // number = 111;
    // dDListInsert(l, &number, 2);
    // DListPrint(l);
    // printf("After deleting element.\n");
    // dDListDeleteElement(l, 10);
    // DListPrint(l);

    printf("\nNew DList\n");

    DList *l1 = dDListCreate(sizeof(int));
    int number = 100;
    int OutNumber = 0;
    for(int i = 0; i < 10; i++){
        dDListAppend(l1, &number);
        number += 100;
    }
    printf("\nOutput using list transverseFD.\n");
    for(int i = 0; i < 10; i++){
        dDListTransverseFd(l1, &OutNumber);
        printf("%d\n",OutNumber);
    }
    printf("\nOutput using list transverseBK.\n");
    for(int i = 0; i < 10; i++){
        dDListTransverseBK(l1, &OutNumber);
        printf("%d\n",OutNumber);
    }



    return 0;
}
