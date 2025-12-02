#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"binarySearchTree.h"

// BST Node
struct Node{
    Node *left;
    Node *right;
    int data;
};

// Creates node with given data and returns pointer to it
Node *BSTNodeCreate(int data){
    Node *node = malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}

// Insert data with given node as root
Node *BSTInsert(Node *root, int data){
    if(root == NULL){
        root = BSTNodeCreate(data);
    }
    else if(root->data > data){
        root->left = BSTInsert(root->left, data);
    }
    else{
        root->right = BSTInsert(root->right, data);
    }
    return root;
}

// Searches tree for given data and returns 1 if found else 0
int BSTSearch(Node *root, int data){
    if(root == NULL){
        return 0;
    }
    else if (root->data > data){
        // printf("\nSearch -> memory %p -> data %d", root, root->data);
        return BSTSearch(root->left, data);
    }
    else if (root->data < data){
        // printf("\nSearch -> memory %p -> data %d", root, root->data);
        return BSTSearch(root->right, data);
    }
    else if(root->data == data){
        // printf("\nSearch -> memory %p -> data %d", root, root->data);
        return 1;
    }
    return 0;
}

// Returns node with minimum value
Node *BSTMin(Node *root){
    if(root->left != NULL){
        return BSTMin(root->left);
    }
    return root;
}

// Returns node with maximum value
Node *BSTMax(Node *root){
    if(root->right != NULL){
        return BSTMin(root->right);
    }
    return root;
}

// Removes node which has same data as given data
Node *BSTDelete(Node *root, int data){
    if(root == NULL){
        return NULL;
    }
    if(root->data < data){ // if data is smaller than node's data call same for right child node
        root->right = BSTDelete(root->right, data);
    }
    else if(root->data > data){ // if data is bigger than node's data call same for left child node
        root->left = BSTDelete(root->left, data);
    }
    else{ // If node's data is same as given data
        if(root->left == NULL && root->right == NULL){ // If both child of node is null(Leaf node) directly free node
            free(root);
            return NULL;
        }
        else if(root->left == NULL){ // if only left node is null make node's right child current node
            Node *temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if(root->right == NULL){ // if only right node is null make node's left child current node
            Node *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        else{ // If node has both child than makes left child current node
            Node* succ = BSTMin(root->right);
            root->data = succ->data;
            root->right = BSTDelete(root->right, succ->data);
        }   
    }
    return root;
}

// Returns data stored in given node
int BSTValue(Node *node){
    return node->data;
}

// Returns left child node of given node
Node *BSTNodeLeft(Node *Node){
    return Node->left;
}

// Returns right child node of given node
Node *BSTNodeRight(Node *Node){
    return Node->right;
}

// Returns height of tree
int BSTHeight(Node *root){
    if(root == NULL){
        return -1;
    }
    if(BSTHeight(root->left) < BSTHeight(root->right)){
        return BSTHeight(root->right) + 1;
    }
    return BSTHeight(root->left) + 1;
}

// Returns total node of tree
int BSTTotalNode(Node *root){
    if(root == NULL){
        return 0;
    }
    return BSTTotalNode(root->left) + BSTTotalNode(root->right) + 1;
}

// Transvers function Left -> Root -> Right
// Used for accessing elements in sorted order
Node *BSTinorder(Node *root){
    if(root->left){
        BSTinorder(root->left);
    }
    printf("Value %d\n", root->data);
    if(root->right){
        BSTinorder(root->right);
    }
    return NULL;
}


// int main(){

//     // Binary search tree
//     Node *n = BSTNodeCreate(10);
//     int number = 5;

//     BSTInsert(n, 5);
//     BSTInsert(n, 15);
//     BSTInsert(n, 1);
//     BSTInsert(n, 8);
//     BSTInsert(n, 13);
//     BSTInsert(n, 18);
//     printf("Tree after adding elements");
//     BSTinorder(n);

//     number = 1;
//     BSTDelete(n, number);
//     if(BSTSearch(n, number)){
//         printf("\nFound %d in tree.\n", number);
//     }
//     else{
//         printf("\nCan not find %d in tree.\n", number);
//     }
//     BSTinorder(n);

//     printf("Height of tree is %d\n", BSTHeight(n));
//     printf("Total node(s) of tree is %d\n", BSTTotalNode(n));


//     return 0;
// }