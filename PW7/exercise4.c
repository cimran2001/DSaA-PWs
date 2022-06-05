#include <stdio.h>
#include "BinaryTree.h"


void mirrorTree(struct Node *node);

int main() {
    
}

void mirrorTree(struct Node *node) {
    if (node == NULL)
        return;

    struct Node *temp = node->left;
    node->left = node->right;
    node->right = temp;

    mirrorTree(node->left);
    mirrorTree(node->right);
}
