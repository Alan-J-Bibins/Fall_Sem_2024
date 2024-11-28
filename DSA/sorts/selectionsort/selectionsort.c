#include <stdio.h>
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int* arr, int length)
{
    for (int i = 0; i < length - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (*(arr + minIndex) > *(arr + j))
                minIndex = j;
        }
        if (minIndex != i)
            swap((arr + minIndex), (arr + i));
    }
}

int main(void)
{
    int n = 0;
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}
