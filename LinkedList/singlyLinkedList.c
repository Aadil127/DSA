#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"singlyLinkedList.h"

// Creates empty list for given data type and returns pointer of the list
List *listCreate(size_t elementSize){
    List *l = calloc(1, sizeof(List));
    l->head = calloc(1, sizeof(Node));
    l->length = 0;
    l->elementSize = elementSize;
    return l;
}

// Create node of the list and returns pointer of that node
Node *listNodeCreate(List *l, void *element){
    Node *newNode = malloc(sizeof(Node));
    newNode->element = malloc(l->elementSize);
    memcpy(newNode->element, element, l->elementSize);
    newNode->next = NULL;
    return newNode;
}

// Adds element at the end of the list
void listAppend(List *l, void *element){
    if(l->length == 0){
        l->head = listNodeCreate(l, element);
    }
    else{
        Node *currentNode = l->head;
        while (currentNode->next){
            currentNode = currentNode->next;
        }
        currentNode->next = listNodeCreate(l, element);
    }
    l->length++;
}

// Adds element at given index
void listInsert(List *l, void *element, int index){
    if(index > l->length){
        printf("\nCan not access index that is outside of a list\n");
        return;
    }
    // Inserting element in front of a list
    if(index == 0){

        if(l->length > 0){
            Node *newNode = malloc(sizeof(Node));
            newNode->element = malloc(l->elementSize);
            memcpy(newNode->element, element, l->elementSize);
            newNode->next = l->head;
            l->head = newNode;
        }
        else{
            //if list is empty
            l->head = listNodeCreate(l, element);
        }
    }
    else{
        //For adding element in the middle of a list
        int currentIndex = 0;
        Node *currentNode = l->head;
        while (currentNode->next){
            if(currentIndex == index - 1) break;
            currentNode = currentNode->next;
            currentIndex++;
        }
        Node *newNode = malloc(sizeof(Node));
        newNode->element = malloc(l->elementSize);
        memcpy(newNode->element, element, l->elementSize);
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
    l->length++;
}

// Removes element of a list at given index
void listDeleteElement(List *l, int index){
    if(index == 0){
        // Removes old head node and makes pointer of the list point to next node
        Node *oldHead = l->head;
        l->head = l->head->next;
        free(oldHead->element);
        free(oldHead);
    }
    else if(index == l->length - 1){
        Node *currentNode = l->head;
        int currentIndex = 0;
        while (currentNode->next && currentIndex < index - 1){
            currentNode = currentNode->next;
            currentIndex++;
        }
        free(currentNode->next->element);
        free(currentNode->next);
        currentNode->next = NULL;
    }
    else{
        Node *node = l->head;
        int currentIndex = 0;
        while (node->next){
            if(currentIndex == index - 1) break;
            node = node->next;
            currentIndex++;
        }
        Node *tempNode = node->next;
        node->next = tempNode->next;
        free(tempNode->element);
        free(tempNode);
    }
    l->length--;
}

// Returns length of given list
int listLen(List *l){//Not really need can directly access it.
    return l->length;
}

// Returns 1 if list in empty else 0
int listEmpty(List *l){
    return l->length == 0;
}

// Moves to next node in each function call starting from head and retruns element of each node
void dDListTransverseFd(List *l, void *element){
    if(listEmpty(l)){
        printf("List in empty.");
        exit(1);
    }
    static Node *n = NULL;
    if(n == NULL){
        n = malloc(sizeof(Node));
        n = l->head;
    }
    else{
        n = n->next;
    }
    memcpy(element, n->element, l->elementSize);
}



void listPrint(List *l){
    Node *n = l->head;
    int index = 0;
    while (n->next){
        printf("index : %d Value %d\n", index, *(int *)n->element);
        n = n->next;
        index++;
    }
    printf("index : %d Value %d\n", index, *(int *)n->element);
}


int main(){
    List *l = listCreate(sizeof(int));
    int number = 100;
    for(int i = 0; i < 10; i++){
        listAppend(l, &number);
        number += 100;
    }
    number = 111;
    listInsert(l, &number, 2);
    listPrint(l);
    printf("After deleting element.\n");
    listDeleteElement(l, 10);
    listPrint(l);
    return 0;
}