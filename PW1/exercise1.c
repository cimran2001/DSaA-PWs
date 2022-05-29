#include <stdio.h>



int sumOfArray(int *arr, int size);


int main() {
    int numbers[] = {1, 2, 3, 4, 5};

    int sum = sumOfArray(numbers, 5);

    printf("The sum is %d.\n", sum);

    return 0;
}


int sumOfArray(int *arr, int size) {
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += arr[i];

    return sum;
}
