#include <stdio.h>
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertionSort(int* arr, int length)
{
    for (int i = 0; i < length; i++) {
        int j = i;
        while (j > 0 && *(arr + j) < *(arr + (j - 1))) {
            swap((arr + (j - 1)), (arr + j));
            j--;
        }
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
    insertionSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
};
