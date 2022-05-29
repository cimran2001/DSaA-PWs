#include "DoublyLinkedList.h"

struct DoublyLinkedList createDoublyLinkedList() {
    struct DoublyLinkedList list;

    list.head = NULL;
    list.tail = NULL;
    list.size = 0;

    return list;
}

struct Node *createNode(int value, struct Node *previous, struct Node *next) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    node->value = value;
    node->previous = previous;
    node->next = next;

    return node;
}

void appendToList(struct DoublyLinkedList *list, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->value = value;
    newNode->previous = list->tail;
    newNode->next = list->head;

    if (list->size == 0) {
        list->tail = newNode;
        list->head = newNode;
        newNode->next = newNode;
        newNode->previous = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
        list->head->previous = newNode;
    }

    list->size++;
}

void clearList(struct DoublyLinkedList *list) {
    struct Node *node = list->head;

    do {
        struct Node *next = node->next;
        free(node);
        node = next;
    } while (node != list->head);

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

void printList(struct DoublyLinkedList list) {
    struct Node *node = list.head;

    do {
        printf("%d ", node->value);
        node = node->next;
    } while (node != list.head);

    printf("\n");
}
