#include <stdio.h>
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int* arr, int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1], right[n2];
    for (i = 0; i < n1; i++) {
        left[i] = *(arr + low + i);
    }
    for (j = 0; j < n2; j++) {
        right[j] = *(arr + mid + j + 1);
    }

    i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
            arr[k++] = left[i];
            i++;
        } else {
            arr[k++] = right[j];
            j++;
        }
    }

    while(i < n1){
        arr[k++] = left[i++];
    }

    while(j < n2){
        arr[k++] = right[j++];
    }
}

void mergesort(int* arr, int low, int high)
{
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main(void)
{
    int arr[] = { 1, 23, 5, 2, 3, 4 };
    mergesort(arr, 0, 5);
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
