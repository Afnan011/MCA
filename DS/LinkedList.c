#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;


void insertAtBeg(int data);
void insertAtEnd(int data);

void deleteAtBeg();
void deleteAtEnd();
void deleteAtIndex(int pos);

void printList();
int countNode();

node *head = NULL;

void main()
{

    int ch, item, pos;

    do
    {
        printf("\n1.Insert At Begining \n2.Insert At End \n\n3.Delete At Begining \n4.Delete At End \n5.Delete At Position \n\n6.Display\n");
        printf("\npress 0 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1: 
                printf("\nEnter item to be inserted: ");
                scanf("%d", &item);
                insertAtBeg(item);
                break;

        case 2: 
                printf("\nEnter item to be inserted: ");
                scanf("%d", &item);
                insertAtEnd(item);
                break;

        case 3: deleteAtBeg();
                break;

        case 4: deleteAtEnd();
                break;

        case 5: 
                printf("\nEnter position to be deleted: ");
                scanf("%d", &pos);
                deleteAtIndex(pos);
                break;

        case 6: printList();
                break;
        
        default: printf("Please enter a valid position");         
        }

    }while (ch != 0);
    


}

int countNode()
{
    int i = 0;
    node *ptr = head;

    while (ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }

    return i;
}

void printList()
{

    int n = countNode();
    if (n <= 0)
    {
        printf("\n*********************");
        printf("\nNo elements found!\n");
        printf("*********************\n");
        return;
    }

    node *ptr = head;
    printf("\n*********************\n");
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    printf("*********************\n");
}

void insertAtBeg(int data)
{
    node *newNode = (node *)malloc(sizeof(node));

    newNode->data = data;
    newNode->next = head;

    head = newNode;
}

void insertAtEnd(int data)
{
    node *newNode = (node *)malloc(sizeof(node));

    node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    newNode->data = data;
    ptr->next = newNode;
    newNode->next = NULL;
}

void deleteAtBeg()
{
    int n = countNode();
    if (n <= 0)
    {
        printf("No elements found!");
        return;
    }

    node *ptr = head;
    head = head->next;

    printf("%d removed from the list.\n", ptr->data);
    free(ptr);
}

void deleteAtEnd()
{
    int n = countNode();
    if (n <= 0)
    {
        printf("No elements found!");
        return;
    }

    node *ptr;
    node *prev;

    ptr = prev = head;

    while (ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = NULL;

    printf("%d removed from the list.\n", ptr->data);
    free(ptr);
}

void deleteAtIndex(int pos)
{
    int n = countNode();
    if (n <= 0)
    {
        printf("No elements found!");
        return;
    }

    if(pos > n || pos < 0)
    {
        printf("\nInvalid position\n");
        return;
    }

    node *ptr, *prev;

    ptr = head;

    int i = 0;

    while (i != pos-1)
    {
        prev = ptr;
        ptr = ptr->next;
        i++;
    }

    prev->next = ptr->next;
    ptr->next = NULL;
    
    printf("%d removed from the list.\n", ptr->data);
    free(ptr);
}