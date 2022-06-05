#include <stdio.h>
#include <stdbool.h>
#include "BinaryTree.h"


bool isBST(struct Node *tree);


int main() {
    struct Node *tree = createTree(5);

    insertInBinaryTree(tree, 3);
    insertInBinaryTree(tree, 6);
    insertInBinaryTree(tree, 1);
    insertInBinaryTree(tree, 4);
    insertInBinaryTree(tree, 8);

    if (isBST(tree))
        puts("BST.");
    else 
        puts("Not BST.");

    clearTree(tree);
    tree = NULL;
}

bool isBST(struct Node *tree) {
    if (tree->left != NULL) {
        if (tree->left->value > tree->value)
            return false;
        else if (!isBST(tree->left))
            return false;
    }

    if (tree->right != NULL) {
        if (tree->right->value < tree->value)
            return false;
        else if (!isBST(tree->right))
            return false;
    }

    return true;
}
