#include <stdio.h>
#include <stdbool.h>
#include "BinaryTree.h"


bool isMaxHeap(struct Node *node);

int main() {
    struct Node *tree = createTree(5);

    insertInBinaryTree(tree, 3);
    insertInBinaryTree(tree, 6);
    insertInBinaryTree(tree, 1);
    insertInBinaryTree(tree, 4);
    insertInBinaryTree(tree, 8);

    if (isMaxHeap(tree))
        puts("Max heap.");
    else 
        puts("Not max heap.");

    clearTree(tree);
    tree = NULL;

    tree = createTree(5);
    insertInBinaryTree(tree, 4);
    insertInBinaryTree(tree, 3);
    insertInBinaryTree(tree, 2);
    insertInBinaryTree(tree, 1);

    if (isMaxHeap(tree))
        puts("Max heap.");
    else 
        puts("Not max heap.");

    clearTree(tree);
    tree = NULL;
    
    return 0;
}

bool isMaxHeap(struct Node *node) {
    if (node->left != NULL) {
        if (node->left->value > node->value)
            return false;
        else if (!isMaxHeap(node->left))
            return false;
    }
    
    if (node->right != NULL) {
        if (node->right->value > node->value)
            return false;
        else if (!isMaxHeap(node->right))
            return false;
    }

    return true;
}