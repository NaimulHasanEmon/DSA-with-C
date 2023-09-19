#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

struct Node *head;

void enqueue(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    node *currNode = head;
    while (currNode->next != NULL)
    {
        currNode = currNode->next;
    }
    currNode->next = newNode;
}

void dequeue()
{
    if (head == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    node *currNode = head;
    printf("Dequeued element is: %d\n", head->data);
    head = head->next;
    free(currNode);
    currNode = NULL;
}

void printQueue()
{
    if (head == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    node *currNode = head;
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
        dequeue();
        printQueue();
        printf("\n");
    }
    free(head);
    head = NULL;
    return 0;
}
