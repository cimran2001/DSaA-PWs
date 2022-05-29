#include <stdio.h>

void QuickSort(int *array, int left, int right);

int main() {
    const int size = 8;
    int a[8] = {20, 3, 45, 500, 22, 13, 120, 95};
    QuickSort(a, 0, size - 1);

    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    puts("");
    return 0;
}

void QuickSort(int *array, int left, int right) {
    int l = left, r = right;
    int pivot = array[(left + right) / 2];

    while (l < r) {
        while (array[l] > pivot) l++;
        while (array[r] < pivot) r--;

        if (l <= r) {
            int temp = array[l];
            array[l++] = array[r];
            array[r--] = temp;
        }
    }

    if (left < l)
        QuickSort(array, left, r);
    if (r < right)
        QuickSort(array, l, right);
}
