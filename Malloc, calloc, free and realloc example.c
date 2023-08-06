#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr1, *ptr2;
    ptr1 = (int *)malloc(5 * sizeof(int));
    ptr2 = (int *)calloc(5, sizeof(int));
    int count = 0, temp = 0;
    if (ptr1 == NULL || ptr2 == NULL)
        printf("Memory not allocated.\n");
    else
    {
        printf("Memory allocated.\n");
        ptr1 = realloc(ptr1, 50);
        count++;
    }
    if (count)
    {
        printf("Memory reallocation successful.\n");
        free(ptr1);
        temp++;
    }
    else
        printf("Memory reallocation not successful.\n");
    if (temp)
        printf("Memory free is successful.\n");
    else
        printf("Memory free is not successful.\n");
    return 0;
}
