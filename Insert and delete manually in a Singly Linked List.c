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

node *insertAtIndex(node *head, int data, int index)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    int i = 0;
    node *currNode = head;
    while (i != index - 1)
    {
        currNode = currNode->next;
        i++;
    }
    newNode->next = currNode->next;
    currNode->next = newNode;
    return head;
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

node *deleteFirst(node *head)
{
    if (head == NULL)
        return NULL;
    return head->next;
}
node *deleteLast(node *head)
{
    if (head->next == NULL || head == NULL)
        return NULL;
    node *secondLastNode = head;
    node *lastNode = head->next;
    while (lastNode->next != NULL)
    {
        secondLastNode = lastNode;
        lastNode = lastNode->next;
    }
    secondLastNode->next = NULL;
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
    int n, key, data, index;
    scanf("%d", &n);
    printf("If you want to add numbers at first then press 1\nIf you want to add at last then press 2: ");
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
        printf("Invalid inpur for insertion.\n");
        break;
    }
    printf("If you want to add at any index then press 3: ");
    scanf("%d", &key);
    switch (key)
    {
    case 3:
        printf("Enter data: ");
        scanf("%d", &data);
        printf("Enter the index no: ");
        scanf("%d", &index);
        head = insertAtIndex(head, data, index);
        printList(head);
        break;
    default:
        printf("Invalid input for index.\n");
        break;
    }
    printf("If you want to delete first then press 4\nIf you want to delete last then press 5: ");
    scanf("%d", &key);
    switch (key)
    {
    case 4:
        head = deleteFirst(head);
        printList(head);
        break;
    case 5:
        head = deleteLast(head);
        printList(head);
        break;
    default:
        break;
    }
    free(head);
    return 0;
}
