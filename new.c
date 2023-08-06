#include <stdio.h>
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int low_index = 0, high_index = 4, mid_index, n;
    printf("Enter the number you want to search: ");
    scanf("%d", &n);
    while (low_index <= high_index)
    {
        mid_index = (high_index + low_index) / 2;
        if (arr[mid_index] == n)
        {
            printf("Found at %d\n", mid_index);
            break;
        }
        else if (arr[mid_index] > n)
            low_index = mid_index + 1;
        else
            high_index = mid_index - 1;
    }
    if (low_index > high_index)
        printf("%d is not in the array elements.\n", n);
    return 0;
}