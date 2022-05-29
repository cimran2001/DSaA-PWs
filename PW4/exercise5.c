#include <stdio.h>
#include <stdlib.h>


struct LinkedList {
    struct Node *head;
    int size;
};

struct Node {
    int val;
    struct Node *next;
};

struct LinkedList createLinkedList();
struct Node *createNode(int val, struct Node *next);
void appendToLinkedList(struct LinkedList *list, int val);
void clearLinkedList(struct LinkedList *list);
void printLinkedList(struct LinkedList list);

void reverseLinkedList(struct LinkedList *list);

int main() {
    struct LinkedList list = createLinkedList();

    appendToLinkedList(&list, 1);
    appendToLinkedList(&list, 2);
    appendToLinkedList(&list, 3);
    appendToLinkedList(&list, 4);
    appendToLinkedList(&list, 5);
    appendToLinkedList(&list, 0);
    printLinkedList(list);

    reverseLinkedList(&list);
    printLinkedList(list);

    clearLinkedList(&list);

    return 0;
}

struct LinkedList createLinkedList() {
    struct LinkedList list;

    list.head = NULL;
    list.size = 0;

    return list;
}

struct Node *createNode(int val, struct Node *next) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    node->val = val;
    node->next = next;

    return node;
}

void appendToLinkedList(struct LinkedList *list, int val) {
    if (list == NULL)
        return;
    
    list->size++;
    struct Node *new = createNode(val, NULL);

    if (list->head == NULL) {
        list->head = new;
        return;
    }

    struct Node *current = list->head;
    while (current->next != NULL)
        current = current->next;

    current->next = new;
}

void clearLinkedList(struct LinkedList *list) {
    if (list == NULL)
        return;

    while (list->head != NULL) {
        struct Node *next = list->head->next;
        free(list->head);
        list->head = next;
    }
}

void printLinkedList(struct LinkedList list) {
    struct Node *node = list.head;

    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

void reverseLinkedList(struct LinkedList *list) {
    if (list == NULL || list->head == NULL)
        return;

    if (list->size == 1)
        return;

    if (list->size == 2) {
        struct Node *temp = list->head;

        list->head = list->head->next;

        list->head->next = temp;
        return;
    }

    struct Node *previous = NULL;
    struct Node *current = list->head;
    struct Node *next = current->next;


    while (current != NULL) {
        current->next = previous;
        previous = current;

        if (next == NULL)
            break;

        struct Node *temp = next;
        next = next->next;
        current = temp;
    }

    list->head = current;
}
