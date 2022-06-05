#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"
#define HASH_TABLE_SIZE 11

int hash_function(int key);
void insert_value();

int main() {
    struct DoublyLinkedList hash[HASH_TABLE_SIZE];
}

int hash_function(int key) {
    return (2 * key) % 11;
}