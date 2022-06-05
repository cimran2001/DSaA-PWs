#include <stdio.h>
#include <stdbool.h>
#include "BinaryTree.h"


bool printAncestors(struct Node *node, int value);

int main() {
    struct Node *tree = createTree(5);

    insertInBinaryTree(tree, 3);
    insertInBinaryTree(tree, 6);
    insertInBinaryTree(tree, 1);
    insertInBinaryTree(tree, 4);
    insertInBinaryTree(tree, 8);

    printAncestors(tree, 1);
    printf("\n");

    clearTree(tree);
    tree = NULL;
    return 0;
}

bool printAncestors(struct Node *node, int value) {
    if (node == NULL)
        return false;
    
    if (node->value == value)
        return true;
    
    if (printAncestors(node->left, value)) {
        printf("%d ", node->value);
        return true;
    }

    if (printAncestors(node->right, value)) {
        printf("%d ", node->value);
        return true;
    }

    return false;
}
