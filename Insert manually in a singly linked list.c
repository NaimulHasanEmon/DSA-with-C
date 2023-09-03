#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *insertAtFirst(node *head, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
        return newNode;
    newNode->next = head;
    return newNode;
}

node *insertAtLast(node *head, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
        return newNode;
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
    struct Node *head = NULL;
    printf("Enter how many elements you want to add: ");
    int n, data;
    scanf("%d", &n);
    printf("If you want to add numbers at first then press 1  and if you want to add at last then press 2: ");
    int key;
    scanf("%d", &key);
    switch (key)
    {
    case 1:
        for (int i = 0; i < n; i++)
        {
            printf("Enter data of list no %d: ", i + 1);
            scanf("%d", &data);
            head = insertAtFirst(head, data);
        }
        printList(head);
        break;
    case 2:
        for (int i = 0; i < n; i++)
        {
            printf("Enter data of list no %d: ", i + 1);
            scanf("%d", &data);
            head = insertAtLast(head, data);
        }
        printList(head);
        break;
    default:
        printf("Wrong key submission.\n");
        break;
    }
    free(head);
    return 0;
}
