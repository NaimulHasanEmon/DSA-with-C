#include <stdio.h>

// Merge sort algorithm
// Time complexity O(nlogn)

void conquer(int arr[], int si, int mid, int ei)
{
    int merged[ei - si + 1];
    int idx1 = si, idx2 = mid + 1, x = 0;
    while (idx1 <= mid && idx2 <= ei)
    {
        if (arr[idx1] <= arr[idx2])
            merged[x++] = arr[idx1++];
        else
            merged[x++] = arr[idx2++];
    }
    while (idx1 <= mid)
    {
        merged[x++] = arr[idx1++];
    }
    while (idx2 <= ei)
    {
        merged[x++] = arr[idx2++];
    }
    for (int i = 0; i < ei - si + 1; i++)
    {
        arr[si + i] = merged[i];
    }
}
void divide(int arr[], int si, int ei)
{
    if (si >= ei)
        return;
    int mid = si + (ei - si) / 2;
    divide(arr, si, mid);
    divide(arr, mid + 1, ei);
    conquer(arr, si, mid, ei);
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int arr[] = {7, 9, 5, 8, 1, 4, 5, 2, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);
    divide(arr, 0, n - 1);
    printf("\nSorted array: ");
    printArray(arr, n);
    return 0;
}
