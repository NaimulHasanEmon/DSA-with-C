#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char name[20];
    int quantity;
    struct Node *next;
} node;

struct Node *head = NULL;

node *addProduct(node *head, const char *name, int quantity)
{
    node *current = head;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            current->quantity += quantity;
            printf("%s updated in inventory. New quantity: %d\n\n", name, current->quantity);
            return head;
        }
        current = current->next;
    }
    
    node *newProduct = (node *)malloc(sizeof(node));
    if (newProduct == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }
    strcpy(newProduct->name, name);
    newProduct->quantity = quantity;
    newProduct->next = NULL;
    if (head == NULL)
    {
        printf("%s added to inventory with quantity %d\n\n", name, quantity);
        return newProduct;
    }
    node *currProduct = head;
    while (currProduct->next != NULL)
    {
        currProduct = currProduct->next;
    }
    currProduct->next = newProduct;
    printf("%s added to inventory with quantity %d\n\n", name, quantity);
    return head;
}

node *sellProduct(node *head, const char *name, int quantity)
{
    node *current = head;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            if (current->quantity >= quantity)
            {
                current->quantity -= quantity;
                printf("%d %s sold. Remaining quantity: %d\n\n", quantity, name, current->quantity);
            }
            else
            {
                printf("Insufficient quantity of %s to sell.\n\n", name);
            }
            return head;
        }
        current = current->next;
    }
    printf("%s not found in inventory\n", name);
    return head;
}

void displayInventory(node *head)
{
    printf("Current Inventory:\n");
    while (head != NULL)
    {
        printf("%s: %d\n", head->name, head->quantity);
        head = head->next;
    }
}

int main()
{
    int choice;
    char name[20];
    int quantity;
    while (1)
    {
        printf("1. Add Product\n");
        printf("2. Sell Product\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter product name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            head = addProduct(head, name, quantity);
            break;
        case 2:
            printf("Enter product name to sell: ");
            scanf("%s", name);
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);
            head = sellProduct(head, name, quantity);
            break;
        case 3:
            displayInventory(head);
            break;
        case 4:
            while (head != NULL)
            {
                node *temp = head;
                head = head->next;
                free(temp);
            }
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}