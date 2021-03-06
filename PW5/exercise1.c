#include <stdio.h>
#include "DoublyLinkedListInt.h"


int main() {
    struct DoublyLinkedList list = createDoublyLinkedList();

    appendToList(&list, 1);
    appendToList(&list, 7);
    appendToList(&list, 5);
    appendToList(&list, 3);
    appendToList(&list, 0);
    
    struct Node *min = minOfList(list);
    if (min != NULL) 
        printf("Min value - %d\n", min->value);
    
    struct Node *max = maxOfList(list);
    if (max != NULL)
        printf("Max value - %d\n", max->value);

    clearList(&list);

    return 0;
}
