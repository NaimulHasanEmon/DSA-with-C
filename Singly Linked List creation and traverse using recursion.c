#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void LinkedListTraversal(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    printf("%d", ptr->data);
    ptr = ptr->next;
    if (ptr != NULL)
    {
        printf(" -> ");
    }
    LinkedListTraversal(ptr);
}
int main()
{
    struct Node *head, *second, *third, *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 7;
    head->next = second;
    second->data = 45;
    second->next = third;
    third->data = 69;
    third->next = fourth;
    fourth->data = 100;
    fourth->next = NULL;
    LinkedListTraversal(head);
    return 0;
}
