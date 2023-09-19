#include <stdio.h>
#include <stdlib.h>
int F = -1, R = -1;
int *arr;

void enqueue(int data, int n)
{
    if (R == n - 1)
    {
        printf("Queue is full.\n");
        return;
    }
    R++;
    arr[R] = data;
    if (F == -1)
        F = 0;
}

void dequeue()
{
    if (F == -1 && R == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Dequeued element: %d\n", arr[F]);
    if (F == R)
    {
        F = -1;
        R = -1;
        return;
    }
    F++;
}

void printQueue()
{
    if (F >= 0)
    {
        printf("Elements in the queue: ");
        for (int i = F; i <= R; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}

int main()
{
    int data, n;
    printf("How many elements you want to add: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        enqueue(data, n);
    }
    printQueue();
    printf("\nHow many elements you want to dequeue: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        dequeue();
    }
    printQueue();
    return 0;
}
