#include <stdio.h>
#include "DoublyLinkedListInt.h"


int main() {
    struct DoublyLinkedList list = createDoublyLinkedList();

    appendToList(&list, 1);
    appendToList(&list, 7);
    appendToList(&list, 5);
    appendToList(&list, 3);
    appendToList(&list, 0);
    printList(list);

    reverseList(&list);
    printList(list);

    clearList(&list);

    return 0;
}
