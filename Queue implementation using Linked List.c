#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

struct Node *F, *R;
int count = 0;

void enqueue(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (F == NULL)
    {
        F = newNode;
        R = newNode;
        return;
    }
    R->next = newNode;
    R = newNode;
}

void dequeue()
{
    if (F == NULL)
    {
        printf("Queue is empty.");
        count++;
        return;
    }
    node *currNode = F;
    printf("Dequeued element is: %d\n", F->data);
    F = F->next;
    free(currNode);
    currNode = NULL;
}

void printQueue()
{
    if (F == NULL)
    {
        printf("Queue is empty.");
        count++;
        return;
    }
    node *currNode = F;
    printf("Queue elements are: ");
    while (currNode != NULL)
    {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
}

int main()
{
    int data, n;
    printf("Enter how many elements you want to enqueue: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        enqueue(data);
    }
    printQueue();
    printf("\nEnter how many elements you want to dequeue: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (count > 0)
            break;
        dequeue();
        printQueue();
        printf("\n");
    }
    free(F);
    free(R);
    F = NULL;
    R = NULL;
    return 0;
}
