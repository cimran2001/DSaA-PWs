#include <stdio.h>
#include <stdlib.h>


int main() {
    const int size = 10;
    int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int count;
    char direct;

    printf("Enter the number of moves: ");
    scanf("%d%*c", &count);

    printf("Select the direction (l/r): ");
    scanf("%c", &direct);

    if (direct == 'l') {
        for (int _ = 0; _ < count; _++) {
            int val = arr[0];
            for (int i = 1; i < size; i++)
                arr[i - 1] = arr[i];
            arr[size - 1] = val;
        }
    } else {
        for (int _ = 0; _ < count; _++) {
            int val = arr[size - 1];
            for (int i = size - 1; i > 0; i--)
                arr[i] = arr[i - 1];
            arr[0] = val;
        }
    }

    for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]);
    puts("");

    return 0;
}
