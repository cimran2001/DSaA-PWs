#include <stdio.h>
#include "BinaryTree.h"

void printAllPaths(struct Node *tree, int *array, int size);

int main() {
    struct Node *tree = createTree(5);

    insertInBinaryTree(tree, 3);
    insertInBinaryTree(tree, 6);
    insertInBinaryTree(tree, 1);
    insertInBinaryTree(tree, 4);
    insertInBinaryTree(tree, 8);
    
    printAllPaths(tree, NULL, 0);

    clearTree(tree);
    tree = NULL;
    return 0;
}

void printAllPaths(struct Node *tree, int *array, int size) {
    if (tree == NULL)
        return;

    int *newArray = (int *)malloc(sizeof(int) * (size + 1));

    for (int i = 0; i < size; i++)
        newArray[i] = array[i];
    newArray[size] = tree->value;

    if (tree->left == NULL && tree->right == NULL) {
        for (int i = 0; i <= size; i++)
            printf("%d ", newArray[i]);
        printf("\n");

        free(newArray);
        return;
    }

    printAllPaths(tree->left, newArray, size + 1);
    printAllPaths(tree->right, newArray, size + 1);
    free(newArray);
}
