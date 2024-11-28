#include <stdio.h>
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;
    for (int j = low + 1; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr + i, arr + j);
        }
    }
    swap(arr + i + 1, arr + high);
    return i + 1;
}

void quicksort(int* arr, int low, int high)
{
    if (low < high) {
        int partitionIndex = partition(arr, low, high);
        quicksort(arr, low, partitionIndex - 1);
        quicksort(arr, partitionIndex + 1, high);
    }
}

int main(void)
{
    int arr[] = { 1, 23, 5, 2, 3, 4 };
    quicksort(arr, 0, 5);
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
