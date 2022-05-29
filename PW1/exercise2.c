#include <stdio.h>
#include <stdlib.h>


enum Type { EVEN, ODD };


int getCount(int *arr, int size, enum Type type);
void copyNumbersByType(int *dest, int *arr, int size, enum Type type);


int main() {
    int numbers[] = {1, 2, 3, 4, 5};

    int *evens, *odds;

    int evensCount = getCount(numbers, 5, EVEN);
    int oddsCount = getCount(numbers, 5, ODD);

    evens = (int *)malloc(sizeof(int) * evensCount);
    odds = (int *)malloc(sizeof(int) * oddsCount);

    copyNumbersByType(evens, numbers, 5, EVEN);
    copyNumbersByType(odds, numbers, 5, ODD);

    for (int i = 0; i < evensCount; i++) 
        printf("%d ", evens[i]);

    for (int i = 0; i < oddsCount; i++) 
        printf("%d ", odds[i]);

    puts("");    
    free(evens);
    free(odds);

    return 0;
}

int getCount(int *arr, int size, enum Type type) {
    int count = 0;

    for (int i = 0; i < size; i++)
        if (arr[i] % 2 == type)
            count++;
    
    return count;
}

void copyNumbersByType(int *dest, int *arr, int size, enum Type type) {
    int index = 0;

    for (int i = 0; i < size; i++)
        if (arr[i] % 2 == type)
            dest[index++] = arr[i];
}
