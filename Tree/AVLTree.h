#ifndef __AVLTree__H
#define __AVLTree__H

typedef struct Node Node;

Node *AVLNodeCreate(int data);

Node *AVLInsert(Node *root, int data);

int AVLValue(Node *node);

Node *AVLNodeLeft(Node *Node);

Node *AVLNodeRight(Node *Node);

int AVLHeight(Node *root);

Node *AVLInorder(Node *root);

Node *AVLRemove(Node *root);

Node *AVLRotateLeft(Node *root);

Node *AVLRotateRight(Node *root);


Node *AVLPrintTree(Node *root, int padding);
#endif