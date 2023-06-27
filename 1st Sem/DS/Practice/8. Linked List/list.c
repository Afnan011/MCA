#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

int countNode();
void printList();

void insertAtBeg(int data);
void insertAtEnd(int data);

void deleteAtBeg();
void deleteAtEnd();
void deleteAtPos(int pos);

node *head = NULL;

void main()
{
    int ch, item, pos;
    do
    {
        printf("\n1.Insert at Beg \t2. Insert at End \n\n3. Delete from beg \t4.Delete from end \t5.Delete from pos \n\n6.Display");
        printf("\npress 0 to exit \n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter item to be inserted : ");
            scanf("%d", &item);
            insertAtBeg(item);
            break;

        case 2:
            printf("Enter item to be inserted : ");
            scanf("%d", &item);
            insertAtEnd(item);
            break;

        case 3:
            deleteAtBeg();
            break;

        case 4:
            deleteAtEnd();
            break;

        case 5:
            if (head == NULL)
            {
                printf("\nList is empty\n");
                break;
            }
            printf("Enter positon to be deleted: ");
            scanf("%d", &pos);
            deleteAtPos(pos);
            break;

        case 6:
            printList();
            break;

        case 0:
            printf("\n\nExiting...\n\n");
            break;

        default:
            printf("\nEnter a valid choice...\n");
            break;
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
        printf("\nList is empty.\n");
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
    printf("\n%d added to the list\n", newNode->data);
}

void insertAtEnd(int data)
{
    if (head == NULL)
    {
        insertAtBeg(data);
        return;
    }

    node *newNode = (node *)malloc(sizeof(node));
    node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    newNode->data = data;
    ptr->next = newNode;
    newNode->next = NULL;

    printf("\n%d added to the list\n", newNode->data);
}

void deleteAtBeg()
{
    if (head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    node *ptr = head;
    head = head->next;

    printf("\n%d removed from the list\n", ptr->data);
    free(ptr);
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    node *ptr, *prev;
    ptr = head;
    prev = NULL;

    while (ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    if (prev == NULL)
    {
        deleteAtBeg();
        return;
    }

    prev->next = NULL;

    printf("\n%d removed from the list\n", ptr->data);
    free(ptr);
}

void deleteAtPos(int pos)
{
    int n = countNode();

    if (pos < 1 || pos > n)
    {
        printf("\nInvalid positio\n");
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
        deleteAtBeg();
        return;
    }

    prev->next = ptr->next;
    ptr->next = NULL;

    printf("\n%d removed from the list\n", ptr->data);
    free(ptr);
}