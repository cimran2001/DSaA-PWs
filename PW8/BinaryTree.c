#include "BinaryTree.h"


struct Node *createTree(int value) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insertInBinaryTree(struct Node *tree, int value) {
    if (tree == NULL)
        return;
    
    while (1) {
        if (tree->value < value) {
            if (tree->right == NULL) {
                tree->right = createTree(value);
                return;
            } else {
                tree = tree->right;
            }
        } else {
            if (tree->left == NULL) {
                tree->left = createTree(value);
                return;
            } else {
                tree = tree->left;
            }
        }
    }
}

void clearTree(struct Node *tree) {
    if (tree == NULL)
        return;

    struct Node *left = tree->left;
    struct Node *right = tree->right;

    free(tree);
    clearTree(left);
    clearTree(right);
}

