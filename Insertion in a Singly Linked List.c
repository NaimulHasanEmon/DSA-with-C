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

node *addAtIndex(node *head, int data, int index)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    node *currNode = head;
    int i = 0;
    while (i != index - 1)
    {
        currNode = currNode->next;
        i++;
    }
    newNode->next = currNode->next;
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
    }
    if (currNode == NULL)
        printf("NULL\n");
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
    node *temp = head;
    printf("How many elements you want to add at first: ");
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Data of %d: ", i + 1);
        scanf("%d", &x);
        temp = addFirst(temp, x);
    }
    printList(temp);
    printf("How many elements you want to add at last: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Data of %d: ", i + 1);
        scanf("%d", &x);
        temp = addLast(temp, x);
    }
    printList(temp);
    printf("Enter the number you want to add in between and its index: ");
    int index;

    // Index has to be greater than 0 because this is for in between.

    scanf("%d%d", &n, &index);
    temp = addAtIndex(temp, n, index);
    printList(temp);
    free(head);
    return 0;
}
