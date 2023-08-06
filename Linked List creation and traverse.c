#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head, *second, *third, *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = NULL;
    struct Node *currNode = head;
    while (currNode != NULL)
    {
        printf("%d -> ", currNode->data);
        currNode = currNode->next;
        if (currNode == NULL)
            printf("NULL");
    }
    free(head);
    free(second);
    free(third);
    free(fourth);
    return 0;
}
