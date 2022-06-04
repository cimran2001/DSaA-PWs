#include "DoublyLinkedListChar.h"

struct DoublyLinkedList createDoublyLinkedList() {
    struct DoublyLinkedList list;

    list.head = NULL;
    list.tail = NULL;
    list.size = 0;

    return list;
}

struct Node *createNode(char value, struct Node *previous, struct Node *next) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    node->value = value;
    node->previous = previous;
    node->next = next;

    return node;
}

void appendToList(struct DoublyLinkedList *list, char value) {
    struct Node *newNode = createNode(value, list->tail, list->head);

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
        printf("%c", node->value);
        node = node->next;
    } while (node != list.head);

    printf("\n");
}

int isPalindrome(struct DoublyLinkedList list) {
    struct Node *start = list.head;
    struct Node *end = list.tail;

    if (start == NULL)
        return 0;

    puts("HERE");

    while (start->value == end->value) {
        if (start == list.tail)
            return 1;
        
        start = start->next;
        end = end->previous;
    }

    return 0;
}
