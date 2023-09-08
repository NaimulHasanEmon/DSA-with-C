#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} node;

node *insertFirst(node *head, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }
    if (head != NULL)
    {
        head->prev = newNode;
    }
    return newNode;
}

node *insertLast(node *head, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }
    if (head == NULL)
    {
        newNode->prev = NULL;
        return newNode;
    }
    node *currNode = head;
    while (currNode->next != NULL)
    {
        currNode = currNode->next;
    }
    currNode->next = newNode;
    newNode->prev = currNode;
    return head;
}

node *insertAtIndex(node *head, int data, int index)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }
    if (index < 0)
    {
        printf("Invalid index.\n");
        return head;
    }
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (index == 0)
        return insertFirst(head, data);
    node *currNode = head;
    int i = 0;
    while (i != index - 1)
    {
        currNode = currNode->next;
        i++;
    }
    if (currNode == NULL)
    {
        printf("Index out of bound.\n");
        free(newNode);
        return head;
    }
    if (currNode->next == NULL)
        return insertLast(head, data);
    newNode->prev = currNode;
    currNode->next->prev = newNode;
    newNode->next = currNode->next;
    currNode->next = newNode;
    return head;
}

node *deleteFirst(node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    node *newHead = head->next;
    newHead->prev = NULL;
    free(head);
    return newHead;
}

node *deleteLast(node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    node *newNode = head;
    while (newNode->next != NULL)
    {
        newNode = newNode->next;
    }
    newNode->prev->next = NULL;
    free(newNode);
    newNode = NULL;
    return head;
}

node *deleteAtIndex(node *head, int index)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }
    if (index < 0)
    {
        printf("Invalid index.\n");
        return head;
    }
    if (index == 0)
    {
        return deleteFirst(head);
    }
    node *currNode = head;
    int i = 0;
    while (i != index)
    {
        currNode = currNode->next;
        i++;
    }
    if (currNode == NULL)
    {
        printf("Index out of bound.\n");
        free(currNode);
        return head;
    }
    if (currNode->next == NULL)
        return deleteLast(head);
    currNode->prev->next = currNode->next;
    currNode->next->prev = currNode->prev;
    free(currNode);
    currNode = NULL;
    return head;
}

void printOriginalList(node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    node *currNode = head;
    printf("List in original order: ");
    while (currNode != NULL)
    {
        printf("%d -> ", currNode->data);
        currNode = currNode->next;
    }
    printf("NULL\n");
}

void printReverseList(node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    node *currNode = head;
    while (currNode->next != NULL)
    {
        currNode = currNode->next;
    }
    printf("List in reverse order: ");
    while (currNode != NULL)
    {
        printf("%d -> ", currNode->data);
        currNode = currNode->prev;
    }
    printf("NULL\n");
}

void freeList(node *head)
{
    node *currNode = head;
    while (currNode != NULL)
    {
        node *nextNode = currNode->next;
        free(currNode);
        currNode = nextNode;
    }
}

int main()
{
    node *head = NULL;
    printf("Enter how nany nodes you want: ");
    int n, data, key, index, count = 0;
    scanf("%d", &n);
    printf("Enter 1 for insert first\nEnter 2 for insert last: ");
    scanf("%d", &key);
    switch (key)
    {
    case 1:
        for (int i = 0; i < n; i++)
        {
            printf("Enter data for add first: ");
            scanf("%d", &data);
            head = insertFirst(head, data);
        }
        break;
    case 2:
        for (int i = 0; i < n; i++)
        {
            printf("Enter data for add last: ");
            scanf("%d", &data);
            head = insertLast(head, data);
        }
        break;
    default:
        printf("Wrong submission for addition.\n");
        count++;
        break;
    }
    printOriginalList(head);
    if (count == 0)
    {
        printReverseList(head);
        printf("Enter 3 for insert at index: ");
        scanf("%d", &key);
        switch (key)
        {
        case 3:
            printf("Enter how many data you want to insert at index: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("Enter data and index for insert ar index: ");
                scanf("%d%d", &data, &index);
                head = insertAtIndex(head, data, index);
            }
            break;
        default:
            printf("Wrong submission for index.\n");
            count++;
            break;
        }
        if (count == 0)
        {
            printOriginalList(head);
            printReverseList(head);
        }
    }
    if (count == 0)
    {
        printf("Enter 4 if you want to delete first node\nEnter 5 if you want to delete last node\nEnter 6 if you want to delete at specific index: ");
        scanf("%d", &key);
        switch (key)
        {
        case 4:
            head = deleteFirst(head);
            break;
        case 5:
            head = deleteLast(head);
            break;
        case 6:
            printf("Enter the index of node that you want to delete: ");
            scanf("%d", &index);
            head = deleteAtIndex(head, index);
            break;
        default:
            printf("Wrong submission for deletion.\n");
            count++;
            break;
        }
        if (count == 0)
        {
            printOriginalList(head);
            printReverseList(head);
        }
    }
    freeList(head);
    return 0;
}
