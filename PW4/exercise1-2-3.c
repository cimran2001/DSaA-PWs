#include <stdio.h>
#include <stdlib.h>


void splitList(int *arr, int size, int **firstHalf, int *firstCount, int **secondHalf, int *secondCount);
int *sortedMerge(int *firstList, int firstCount, int *secondList, int secondCount);
void mergeSort(int *arr, int size);

int main() {
    int arr[10] = {1, 2, 3, 5, 4, 3, 2, 0, 9, 1};
    mergeSort(arr, 10);

    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}


void splitList(int *arr, int size, int **firstHalf, int *firstSize, int **secondHalf, int *secondSize) {
    if (arr == NULL || firstHalf == NULL || secondHalf == NULL || firstSize == NULL || secondSize == NULL)
        return;

    int firstHalfSize = (size + 1) / 2;
    int secondHalfSize = size - firstHalfSize;

    *firstHalf = (int *)malloc(sizeof(int) * firstHalfSize);
    *secondHalf = (int *)malloc(sizeof(int) * secondHalfSize);

    int *first = *firstHalf;
    int *second = *secondHalf;

    for (int i = 0; i < firstHalfSize; i++)
        first[i] = arr[i];

    for (int i = 0; i < secondHalfSize; i++)
        second[i] = arr[firstHalfSize + i];

    *firstSize = firstHalfSize;
    *secondSize = secondHalfSize;
}

int *sortedMerge(int *firstList, int firstCount, int *secondList, int secondCount) {
    if (firstList == NULL || secondList == NULL)
        return NULL;

    int *newArray = (int *)malloc(sizeof(int) * (firstCount + secondCount));

    int firstIndex = 0, secondIndex = 0;
    int index = 0;
    while (firstIndex < firstCount || secondIndex < secondCount) {
        if (firstIndex == firstCount) {
            newArray[index++] = secondList[secondIndex++];
            continue;
        }

        if (secondIndex == secondCount) {
            newArray[index++] = firstList[firstIndex++];
            continue;
        }

        if (firstList[firstIndex] > secondList[secondIndex])
            newArray[index++] = secondList[secondIndex++];
        else 
            newArray[index++] = firstList[firstIndex++];
    }

    return newArray;
}

void mergeSort(int *arr, int size) {
    if (size <= 1)
        return;

    int *firstHalf, *secondHalf;
    int firstHalfSize, secondHalfSize;

    splitList(arr, size, &firstHalf, &firstHalfSize, &secondHalf, &secondHalfSize);
    mergeSort(firstHalf, firstHalfSize);
    mergeSort(secondHalf, secondHalfSize);

    int *newArray = sortedMerge(firstHalf, firstHalfSize, secondHalf, secondHalfSize);
    for (int i = 0; i < size; i++)
        arr[i] = newArray[i];

    free(newArray);
    free(firstHalf);
    free(secondHalf);
}
