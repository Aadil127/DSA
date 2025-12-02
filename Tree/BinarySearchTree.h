#ifndef __binarySearchTree__H
#define __binarySearchTree__H

typedef struct Node Node;

Node *BSTNodeCreate(int data);

Node *BSTInsert(Node *root, int data);

int BSTSearch(Node *root, int data);

Node *BSTMin(Node *root);

Node *BSTMax(Node *root);

Node *BSTNodeDelete(Node *root, int data);

int BSTValue(Node *node);

Node *BSTNodeLeft(Node *Node);

Node *BSTNodeRight(Node *Node);

int BSTHeight(Node *root);

int BSTTotalNode(Node *root);

Node *BSTInorder(Node *root);

Node *BSTPostorder(Node *root);

Node *BSTPreorder(Node *root);

Node *BSTRemove(Node *root);

int BSTEmpty(Node *root);

#endif