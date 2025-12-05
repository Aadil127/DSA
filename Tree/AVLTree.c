#include<stdio.h>
#include<stdlib.h>
#include"AVLTree.h"

// AVL Node
struct Node{
    Node *left;
    Node *right;
    int data, height;
};

// Creates node with given data and returns pointer to it
Node *AVLNodeCreate(int data){
    Node *node = malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    node->height = 0;
    return node;
}

int AVLMax(int left, int right){
    if (left > right){
        return left;
    }
    return right;
}

// Insert data with given node as root
Node *AVLInsert(Node *root, int data){
    if(root == NULL){
        return AVLNodeCreate(data);
    }
    else if(root->data > data){
        root->left = AVLInsert(root->left, data);
    }
    else{
        root->right = AVLInsert(root->right, data);
    }

    root->height = AVLMax(AVLHeight(root->left), AVLHeight(root->right)) + 1;


    // int balanceFactor = root->left->height - root->right->height;
    int balanceFactor = ((root->left) ? root->left->height : -1) - ((root->right) ? root->right->height : -1);


    // // LL Imbalance (to check if balance factor is greater than 1 and inserted data is less than data of root's left node)
    if(balanceFactor > 1  && data < root->left->data){
        return AVLRotateRight(root);
    }
    // RR Imbalance (to check if balance factor is less than -1 and inserted data is bigger than data of root's right node)
    if(balanceFactor < -1 && data > root->right->data){
        return AVLRotateLeft(root);
    }
    // LR Imbalance (to check if balance factor is greater than 1 and inserted data is bigger than data of root's left node)
    if(balanceFactor > 1 && data > root->left->data){
        root->left = AVLRotateLeft(root);
        return AVLRotateRight(root);
    }
    // RL Imbalance (if balance factor is less than -1 and inserted data is less than data of root's right node)
    if(balanceFactor > 1 && data < root->left->data){
        root->right = AVLRotateRight(root);
        return AVLRotateLeft(root);
    }
    return root;
}

// Returns data stored in given node
int AVLValue(Node *node){
    return node->data;
}

// Returns left child node of given node
Node *AVLNodeLeft(Node *Node){
    return Node->left;
}

// Returns right child node of given node
Node *AVLNodeRight(Node *Node){
    return Node->right;
}

// Returns height of tree
int AVLHeight(Node *root){
    if(root == NULL){
        return -1;
    }
    return root->height;
}

// Transvers function Left -> Root -> Right
// Used for accessing elements in sorted order
Node *AVLInorder(Node *root){
    if(root->left){
        AVLInorder(root->left);
    }
    printf("Value %d -> height %d\n", root->data, root->height);
    if(root->right){
        AVLInorder(root->right);
    }
    return NULL;
}

//Frees the memory of a binary tree
Node *AVLRemove(Node *root){
    // Uses postorder transvers
    if(root->left){
        AVLRemove(root->left);
    }
    if(root->right){
        AVLRemove(root->right);
    }
    free(root);
    return NULL;
}


/* 
* Rotates Node to right
*/
Node *AVLRotateRight(Node *root){
    if(root == NULL) return NULL;
    Node *rootL = root->left;
    Node *rootLR = rootL->right;
    rootL->right = root;
    root->left = rootLR;
    root->height = AVLMax(AVLHeight(root->left), AVLHeight(root->right)) + 1;
    rootL->height = AVLMax(AVLHeight(rootL->left), AVLHeight(rootL->right)) + 1;
    return rootL;// New root
}

/* 
* Rotates Node to left
*/
Node *AVLRotateLeft(Node *root){
    if(root == NULL) return NULL;
    Node *rootR = root->right;
    Node *rootRL = rootR->left;
    rootR->left = root;
    root->right = rootRL;
    root->height = AVLMax(AVLHeight(root->left), AVLHeight(root->right)) + 1;
    rootR->height = AVLMax(AVLHeight(rootR->left), AVLHeight(rootR->right)) + 1;
    return rootR;// New root
}

// Prints tree in terminal (rootNode, padding in int)
Node *AVLPrintTree(Node *root, int padding){
    if(root->right){
        AVLPrintTree(root->right, padding + 5);
        printf("%*c\n",padding + 4, '/');
    }
    printf("%*c(%d)%d\n", padding, ' ' , root->data, root->height);
    if(root->left){
        printf("%*c\n",padding + 4, '\\');
        AVLPrintTree(root->left, padding + 5);
    }
    return NULL;
}