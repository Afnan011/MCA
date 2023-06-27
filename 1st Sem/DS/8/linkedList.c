#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void printList();
int countNode();

void insertAtBeg(int data);
void insertAtEnd(int data);

void deleteFromBeg();
void deleteFromEnd();
void deleteFromPos(int pos);

node *head = NULL;

void main()
{
    int ch, item, pos;

    do
    {
        printf("\n1.Insert At Begining \t2.Insert At End \n\n3.Delete At Begining \t4.Delete At End \n5.Delete At Position \n\n6.Display\n");
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

        case 3:
            deleteFromBeg();
            break;

        case 4:
            deleteFromEnd();
            break;

        case 5:
            printf("\nEnter position to be deleted: ");
            scanf("%d", &pos);
            deleteFromPos(pos);
            break;

        case 6:
            printList();
            break;

        default:
            printf("Please enter a valid position");
        }

    } while (ch != 0);
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
    if (head == NULL)
    {
        printf("\nEmpty List");
        return;
    }

    node *ptr = head;
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
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
    if (head == NULL)
    {
        insertAtBeg(data);
        return;
    }

    node *ptr = head;
    node *newNode = (node *)malloc(sizeof(node));

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    newNode->data = data;
    ptr->next = newNode;
    newNode->next = NULL;
}

void deleteFromBeg()
{
    if (head == NULL)
    {
        printf("No elements found!");
        return;
    }

    node *ptr = head;
    head = head->next;

    printf("%d removed from the list.\n", ptr->data);
    free(ptr);
}

void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("No elements found!");
        return;
    }

    node *ptr;
    node *prev;

    ptr = head;
    prev = NULL;

    while (ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    if (prev == NULL)
    {
        deleteFromBeg();
        return;
    }

    prev->next = NULL;

    printf("%d removed from the list.\n", ptr->data);
    free(ptr);
}

void deleteFromPos(int pos)
{
    int n = countNode();
    if (head == NULL)
    {
        printf("No elements found!");
        return;
    }

    if (pos < 1 || pos > n)
    {
        printf("\nInvalid position\n");
        return;
    }

    node *ptr, *prev;

    ptr = head;

    int i = 0;

    while (i != pos - 1)
    {
        prev = ptr;
        ptr = ptr->next;
        i++;
    }

    if (i == 0)
    {
        deleteFromBeg();
        return;
    }

    prev->next = ptr->next;
    ptr->next = NULL;

    printf("%d removed from the list.\n", ptr->data);
    free(ptr);
}