#include <stdio.h>
#define size 5
int F = -1, R = -1;
int arr[size];

void enqueue(int data)
{
    if ((R + 1) % size == F)
    {
        printf("Queue is full.\n");
    }
    else if (F == -1 && R == -1)
    {
        F = 0;
        R = 0;
        arr[R] = data;
    }
    else
    {
        R = (R + 1) % size;
        arr[R] = data;
    }
}

void dequeue()
{
    if (F == -1 && R == -1)
    {
        printf("Queue is empty.\n");
    }
    else if (F == R)
    {
        printf("Dequeued element is: %d\n", arr[F]);
        F = -1;
        R = -1;
    }
    else
    {
        F = (F + 1) % size;
    }
}

void printQueue()
{
    if (F == -1 && R == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    int i = F;
    printf("All elements: ");
    do
    {
        printf("%d ", arr[i]);
        i = (i + 1) % size;
    } while (i != (R + 1) % size);
    printf("\n");
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    printQueue();
    dequeue();
    dequeue();
    printQueue();
    enqueue(7);
    printQueue();
    return 0;
}