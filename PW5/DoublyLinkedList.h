#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *previous;
    struct Node *next;
};

struct DoublyLinkedList {
    struct Node *head;
    struct Node *tail;
    int size;
};

struct DoublyLinkedList createDoublyLinkedList();
struct Node *createNode(int value, struct Node *previous, struct Node *next);
void appendToList(struct DoublyLinkedList *list, int value);
void clearList(struct DoublyLinkedList *list);
void printList(struct DoublyLinkedList list);
struct Node *minOfList(struct DoublyLinkedList list);
struct Node *maxOfList(struct DoublyLinkedList list);

#endif
