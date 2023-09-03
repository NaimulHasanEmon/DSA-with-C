#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;
node *creatList(node *head, int data)
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
    }
    printf("NULL\n");
}
int main()
{
    printf("Enter how many elements you want to add: ");
    int n, data;
    scanf("%d", &n);
    node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        printf("Enter data of list %d: ", i + 1);
        scanf("%d", &data);
        head = creatList(head, data);
    }
    printList(head);
    free(head);
    return 0;
}