#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#include <stdlib.h>

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *createTree(int value);
void insertInBinaryTree(struct Node *tree, int value);
void clearTree(struct Node *tree);


#endif
