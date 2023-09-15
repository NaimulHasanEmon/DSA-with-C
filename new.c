#include <stdio.h>
#include <stdlib.h>
int top = -1;
int *arr;

void sizeofStack()
{
    printf("Size of the stack is: %d\n", top + 1);
}

void printStack(int top)
{
    printf("Stack elements are: ");
    for (int i = 0; i < top + 1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void push(int data, int size)
{
    if (top >= size - 1)
    {
        printf("Stack is full.\n");
        return;
    }
    top++;
    arr[top] = data;
}

void pop()
{
    if (top < 0)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Popped element is: %d\n", arr[top]);
    top--;
}

int main()
{
    int size, data, n;
    printf("How many elements you want to add in stack: ");
    scanf("%d", &size);
    arr = (int *)malloc(size * sizeof(int));
    printf("Enter stack elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &data);
        push(data, size);
    }
    printStack(top);
    printf("How many elements you want to pop from the stack: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printStack(top);
        sizeofStack();
        pop();
        printStack(top);
        printf("\n");
    }
    free(arr);
    return 0;
}