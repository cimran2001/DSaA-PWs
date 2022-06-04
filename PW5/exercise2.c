#include <stdio.h>
#include "DoublyLinkedListChar.h"


int main() {
    struct DoublyLinkedList string = createDoublyLinkedList();

    appendToList(&string, 'h');
    appendToList(&string, 'e');
    appendToList(&string, 'l');
    appendToList(&string, 'l');
    appendToList(&string, 'o');

    printf("'hello' is %sa palindrome.\n", isPalindrome(string) ? "" : "not ");

    clearList(&string);

    appendToList(&string, 'l');
    appendToList(&string, 'o');
    appendToList(&string, 'l');

    printf("'lol' is %sa palindrome.\n", isPalindrome(string) ? "" : "not ");

    clearList(&string);

    return 0;
}
