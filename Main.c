#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} node;

void printList(node *currNode)
{
    if (currNode == NULL)
    {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", currNode->data);
    printList(currNode->next);
}

void printRevList(node *currNode)
{
    if (currNode == NULL)
    {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", currNode->data);
    printRevList(currNode->prev);
}

int main()
{
    node *head, *first, *second, *third;
    head = (node *)malloc(sizeof(node));
    first = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    head->prev = NULL;
    head->data = 1;
    head->next = first;
    first->prev = head;
    first->data = 2;
    first->next = second;
    second->prev = first;
    second->data = 3;
    second->next = third;
    third->prev = second;
    third->data = 4;
    third->next = NULL;
    printf("Forward: ");
    printList(head);
    printf("Backward: ");
    printRevList(third);
    return 0;
}