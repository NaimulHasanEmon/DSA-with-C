#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

struct Node *top;
int size = 0;

void push(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    size++;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    node *currNode = top;
    top = top->next;
    free(currNode);
    currNode = NULL;
    size--;
}

void sizeOfList()
{
    printf("List size is: %d\n", size);
}

void printList()
{
    node *tempNode = top;
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("List is: ");
    while (tempNode != NULL)
    {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main()
{
    printf("How many elements you want to add: ");
    int n, data;
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        push(data);
    }
    printList();
    sizeOfList();
    printf("How many elements you want to pop: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        pop();
        printList();
        sizeOfList();
    }
    return 0;
}
