#include <stdio.h> 
#include <stdlib.h> 

struct node {
    int num;
    struct node *next; 
};

int create(struct node **);

int palin_check(struct node *, int count);

int main() {
    struct node *p = NULL;
    int result, count;

    printf("Enter data into the list\n"); 

    count = create(&p);
    result = palin_check(p, count);

    if (result == 1)
        printf("The linked list is a palindrome.\n"); 
    else
        printf("The linked list is not a palindrome.\n"); return 0;
}

int create(struct node **pNode) {
    *pNode = (struct node *)malloc(sizeof(struct node));
    struct node *node = *pNode;

    int count;
    printf("How many elements do you want to add? ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        int value;

        printf("Enter element n.%d: ", i + 1);
        scanf("%d", &value);

        if (i == 0) {
            node->num = value;
            node->next = NULL;
        } else {
            struct node *temp = node;

            while (temp->next != NULL) temp = temp->next;

            temp->next = (struct node *)malloc(sizeof(struct node));
            temp = temp->next;

            temp->num = value;
            temp->next = NULL;
        }
    }

    return count;
}

int palin_check(struct node *pNode, int count) {
    for (int i = 0; i <= count / 2; i++) {
        struct node *left = pNode;

        struct node *right = pNode;

        for (int j = 0; j < i; j++)
            left = left->next;
        
        for (int j = 0; j < count - i - 1; j++)
            right = right->next;

        if (left->num != right->num)
            return 0;
    }
 
    return 1;
}
