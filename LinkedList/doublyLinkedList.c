#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"doublyLinkedList.h"


struct Node{
    void *element;
    Node *next;
    Node *prev;
};

/*
* Singly Linked List
*/
struct List{
    size_t length, elementSize;
    Node *head;
    Node *tail;
};

// Creates Doubly Linked List and returns pointer of the list
List *dListCreate(size_t elementSize){
    List *l = calloc(1, sizeof(List));
    l->head = NULL;
    l->tail = NULL;
    l->length = 0;
    l->elementSize = elementSize;
    return l;
}

// Creates node of the Doubly Linked List and returns pointer of that node
Node *dListNodeCreate(List *l, Node *prev, void *element){
    Node *newNode = malloc(sizeof(Node));
    newNode->element = malloc(l->elementSize);
    memcpy(newNode->element, element, l->elementSize);
    newNode->prev = prev;
    newNode->next = NULL;
    return newNode;
}

// Adds element at the end of the DList
void dListAppend(List *l, void *element){
    if(l->length == 0){
        l->head = dListNodeCreate(l, NULL, element);
    }
    else{
        Node *currentNode = l->head;
        while (currentNode->next){
            currentNode = currentNode->next;
        }
        currentNode->next = dListNodeCreate(l, currentNode, element);
        l->tail = currentNode->next;
    }
    l->length++;
}

// Adds element at given index
void dListInsert(List *l, void *element, int index){
    if((size_t)index > l->length){
        printf("\nCan not access index that is outside of a DList\n");
        return;
    }
    // Inserting element in front of a DList
    if(index == 0){

        if(l->length > 0){
            Node *newNode = malloc(sizeof(Node));
            newNode->element = malloc(l->elementSize);
            memcpy(newNode->element, element, l->elementSize);
            newNode->next = l->head;
            newNode->prev = NULL;
            l->head = newNode;
        }
        else{
            //if DList is empty
            l->head = dListNodeCreate(l, NULL, element);
        }
    }
    else{
        //For adding element in the middle of a DList
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
        newNode->prev = currentNode;
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        l->tail = newNode;
    }
    l->length++;
}


// Removes element of a list at given index
void dListDeleteElement(List *l, int index){
    if(index == 0){
        // Removes old head Dnode and makes pointer of the DList point to next Dnode
        Node *oldHead = l->head;
        l->head = l->head->next;
        free(oldHead->element);
        free(oldHead);
    }
    else if((size_t)index == l->length - 1){
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

// Frees memory of given list
void dListRemove(List *l){
    Node *node = l->head;
    Node *tempNode = node;
    while (node){
        tempNode = node->next;
        free(node->element);
        // free(node->prev);
        free(node);
        node = tempNode;
    }
    // free(l->head);
    free(l);
    // dListTransverseFd(NULL, NULL);
    // dListTransverseBk(NULL, NULL);
}



// Returns length of given list
size_t dListLen(List *l){//Not really need can directly access it.
    return l->length;
}

// Returns 1 if list in empty else 0
int dListEmpty(List *l){
    return l->length == 0;
}

// Moves to next node in each function call starting from head and retruns element of each node
void dListTransverseFd(List *l, void *element){
    if( l != NULL && dListEmpty(l)){
        printf("List in empty.");
        exit(1);
    }

    static Node *n = NULL;
    if(n == NULL){
        n = l->head;
    }
    else{
        n = n->next;
    }
    memcpy(element, n->element, l->elementSize);
}

// Moves to next node in each function call starting from head and retruns element of each node
void *dListTransverseFdReturn(List *l){
    if( l != NULL && dListEmpty(l)){
        printf("List in empty.");
        exit(1);
    }

    static Node *n = NULL;
    if(n == NULL){
        n = l->head;
    }
    else{
        n = n->next;
    }
    return n->element;
}

// Moves to previous node in each function call starting from tail and retruns element of each node
void dListTransverseBk(List *l, void *element){
    if( l != NULL && dListEmpty(l)){
        printf("List in empty.");
        exit(1);
    }

    static Node *n = NULL;
    if(n == NULL){
        n = l->tail;
    }
    else{
        n = n->prev;
    }
    memcpy(element, n->element, l->elementSize);
}

// Moves to previous node in each function call starting from tail and retruns element of each node
void *dListTransverseBkReturn(List *l){
    if( l != NULL && dListEmpty(l)){
        printf("List in empty.");
        exit(1);
    }

    static Node *n = NULL;
    if(n == NULL){
        n = l->tail;
    }
    else{
        n = n->prev;
    }
   return n->element;
}


void dListPrint(List *l){
    Node *n = l->head;
    int index = 0;
    while (n->next){
        printf("index : %d Value %d\n", index, *(int *)n->element);
        n = n->next;
        index++;
    }
    printf("index : %d Value %d\n", index, *(int *)n->element);
}


// int main(){
//     // DList *l = dDListCreate(sizeof(int));
//     // int number = 100;
//     // for(int i = 0; i < 10; i++){
//     //     dDListAppend(l, &number);
//     //     number += 100;
//     // }
//     // number = 111;
//     // dDListInsert(l, &number, 2);
//     // DListPrint(l);
//     // printf("After deleting element.\n");
//     // dDListDeleteElement(l, 10);
//     // DListPrint(l);

//     printf("\nNew DList\n");

//     List *l1 = dListCreate(sizeof(int));
//     int number = 100;
//     int OutNumber = 0;
//     for(int i = 0; i < 10; i++){
//         dListAppend(l1, &number);
//         number += 100;
//     }
//     printf("\nOutput using list transverseFD.\n");
//     for(int i = 0; i < 10; i++){
//         dListTransverseFd(l1, &OutNumber);
//         printf("%d\n",OutNumber);
//     }
//     printf("\nOutput using list transverseBK.\n");
//     for(int i = 0; i < 10; i++){
//         dListTransverseBk(l1, &OutNumber);
//         printf("%d\n",OutNumber);
//     }

//     dListRemove(l1);

//     return 0;
// }
