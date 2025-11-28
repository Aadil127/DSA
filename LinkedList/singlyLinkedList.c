#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"singlyLinkedList.h"

// Creates empty list for given data type and returns pointer of the list
List *listCreate(size_t elementSize) {
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
    if(index > l->length - 1){
        printf("can not access index of side of list.");
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
    // Adding element at the end of a list
    else if(index == -1){

        Node *currentNode = l->head;
        while (currentNode->next){
            currentNode = currentNode->next;
        }
        currentNode->next = listNodeCreate(l, element);
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

int listLen(List *l) {//Not really need can directly access it.
    return l->length;
}

int listEmpty(List *l) {
    return l->length == 0;
}



void listPrint(List *l) {
    Node *n = l->head;
    while (n->next){
        printf("Value %d\n", *(int *)n->element);
        n = n->next;
    }
    printf("Value %d\n", *(int *)n->element);
}


int main() {
    List *l = listCreate(sizeof(int));
    int number = 100;
    for(int i = 0; i < 10; i++){
        listAppend(l, &number);
        number += 100;
    }
    number = 111;
    listInsert(l, &number, 0);
    listPrint(l);
    return 0;
}