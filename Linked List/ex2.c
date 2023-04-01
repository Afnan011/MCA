#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void printList();
void insertAtBeg(int data);
void insertAtIndex(int data, int index);
void insertAtEnd(int data);

node *head = NULL;

void main()
{
    insertAtBeg(10);
    printList();

    insertAtIndex(5, 1);
    printList();


    insertAtIndex(15, 2);
    printList();

    insertAtEnd(20);
    printList();

    insertAtEnd(30);
    printList();

}

void printList()
{
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

void insertAtIndex(int data, int index)
{
    node *newNode = (node *)malloc(sizeof(node));

    node *ptr = head;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }

    newNode->data = data;
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void insertAtEnd(int data)
{
    node *newNode = (node*) malloc(sizeof(node));

    node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    newNode->data = data;
    newNode->next = NULL;

    ptr->next = newNode;
    

}
