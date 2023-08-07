#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *addFirst(node *head, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

node *addLast(node *head, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    node *currNode = head;
    while (currNode->next != NULL)
    {
        currNode = currNode->next;
    }
    currNode->next = newNode;
    return head;
}

void printList(node *head)
{
    node *currNode = head;
    while (currNode != NULL)
    {
        printf("%d -> ", currNode->data);
        currNode = currNode->next;
        if (currNode == NULL)
            printf("NULL\n");
    }
}

int main()
{
    node *head, *second, *third;
    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    printList(head);
    printf("How many nodes you want to add first: ");
    int n, x, y;
    scanf("%d", &n);
    node *temp = head;
    for (int i = 0; i < n; i++)
    {
        printf("Data %d: ", i + 1);
        scanf("%d", &x);
        temp = addFirst(temp, x);
    }
    printList(temp);
    printf("How many nodes you want to add last: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Data %d: ", i + 1);
        scanf("%d", &y);
        temp = addLast(temp, y);
    }
    printList(temp);
    free(head);
    return 0;
}
