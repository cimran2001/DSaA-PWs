#include <stdio.h>
#include <stdlib.h>


int main() {
    const int m = 3, n = 4, size = m + n;
    int **arr1 = (int **)malloc(sizeof(int *) * (m + n));
    for (int i = 0; i < m + n; i++)
        arr1[i] = NULL;

    #pragma region Array from task:
    arr1[0] = (int *)malloc(sizeof(int));
    *arr1[0] = 1;

    arr1[1] = (int *)malloc(sizeof(int));
    *arr1[1] = 5;

    arr1[2] = (int *)malloc(sizeof(int));
    *arr1[2] = 8;
    #pragma endregion 
    int arr2[n] = {0, 4, 7, 10};

    int counter = 0;
    for (int i = size - 1; i > 0; i--) {
        if (arr1[i] != NULL)
            continue;
        
        counter++;
        for (int j = i - 1; j >= 0; j--) {
            if (arr1[j] != NULL) {
                arr1[i] = arr1[j];
                arr1[j] = NULL;
                break;
            }
        }
        if (counter == m)
            break;
    }

    int i = 0;
    int j = size - counter;
    int k = 0;

    for (; i < size; i++) {
        if (k == n || (j != size && *arr1[j] < arr2[k])) {
            int *ptr = arr1[j];
            arr1[j++] = NULL;
            arr1[i] = ptr;
        } else {
            arr1[i] = (int *)malloc(sizeof(int));
            *arr1[i] = arr2[k++];
        }
    }

    int x = 0;
    for (int i = 0; i < size; i++)
        if (arr1[i] == NULL)
            x++;

    for (int i = 0; i < size; i++) {
        printf("%d ", *arr1[i]);
        free(arr1[i]);
    }
    puts("");
    free(arr1);

    

    return 0;
}
