#ifndef __DOUBLY_LINKED_LIST_CHAR_H__
#define __DOUBLY_LINKED_LIST_CHAR_H__

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char value;
    struct Node *previous;
    struct Node *next;
};

struct DoublyLinkedList {
    struct Node *head;
    struct Node *tail;
    int size;
};

struct DoublyLinkedList createDoublyLinkedList();
struct Node *createNode(char value, struct Node *previous, struct Node *next);
void appendToList(struct DoublyLinkedList *list, char value);
void clearList(struct DoublyLinkedList *list);
void printList(struct DoublyLinkedList list);
int isPalindrome(struct DoublyLinkedList list);

#endif
