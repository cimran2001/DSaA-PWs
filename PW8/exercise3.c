#include <stdio.h>
#include "BinaryTree.h"


int findSumTree(struct Node *tree);


int main() {
    struct Node *tree = createTree(5);

    insertInBinaryTree(tree, 3);
    insertInBinaryTree(tree, 6);
    insertInBinaryTree(tree, 1);
    insertInBinaryTree(tree, 4);
    insertInBinaryTree(tree, 8);

    printf("Sum: %d\n", findSumTree(tree));

    clearTree(tree);
    tree = NULL;
}

int findSumTree(struct Node *tree) {
    if (tree == NULL)
        return 0;

    return tree->value + findSumTree(tree->left) + findSumTree(tree->right);
}
