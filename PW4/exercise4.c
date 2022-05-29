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

void removeDuplicates(struct LinkedList *list);

int main() {
    struct LinkedList list = createLinkedList();

    appendToLinkedList(&list, 0);
    appendToLinkedList(&list, 0);
    appendToLinkedList(&list, 0);
    appendToLinkedList(&list, 1);
    appendToLinkedList(&list, 3);
    appendToLinkedList(&list, 3);
    appendToLinkedList(&list, 4);
    appendToLinkedList(&list, 9);
    appendToLinkedList(&list, 9);
    printLinkedList(list);

    removeDuplicates(&list);
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

void removeDuplicates(struct LinkedList *list) {
    if (list->size <= 1)
        return;

    struct Node *current = list->head;
    struct Node *next = current->next;

    while (next != NULL) {
        if (current->val != next->val) {
            current = next;
            next = next->next;
            continue;
        }

        struct Node *newNext = next->next;
        free(next);
        current->next = newNext;
        next = newNext;
    }
}
