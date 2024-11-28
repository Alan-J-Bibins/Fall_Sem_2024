#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void countingSort(int* arr, int length)
{
    // create an array with the same size as input array
    int* output = (int*)calloc(length, sizeof(int));
    // find the max element
    int max = arr[0];
    for (int i = 0; i < length; i++) {
        max = max < arr[i] ? arr[i] : max;
    }

    // make array with counts of elements in the input array
    int* count = (int*)calloc(max + 1, sizeof(int));
    for (int i = 0; i < max + 1; i++) {
        count[arr[i]]++;
    }

    // find the cumulative sum at each index
    for (int i = 1; i < max + 1; i++) {
        count[i] += count[i - 1];
    }

    // cumulative array gives the position of the element in the sorted array so put that in output
    for (int i = length - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    // copy into input array
    for (int i = 0; i < length; i++) {
        arr[i] = output[i];
    }
    free(output);
    free(count);
}

int main(void)
{
    int arr[] = { 1, 1, 4, 4, 5, 6, 2 };
    countingSort(arr, 7);
    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
