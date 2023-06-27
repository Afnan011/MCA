#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void printList(node *ptr);
node *insertAtBeg(node *ptr, int data);
node *insertAtIndex(node *ptr, int data, int index);
node *insertAtEnd(node *ptr, int data);

void main()
{

    node *head = NULL;
    node *secondNode = NULL;
    node *thirdNode = NULL;

    //allocate memory for 3 nodes
    head = (node *) malloc(sizeof(node)); 
    secondNode = (node *) malloc(sizeof(node)); 
    thirdNode = (node *) malloc(sizeof(node)); 

    head -> data = 1;
    head -> next = secondNode;

    secondNode -> data = 2;
    secondNode -> next = thirdNode;
    
    thirdNode -> data = 3;
    thirdNode -> next = NULL;


    printList(head);

    head = insertAtBeg(head, 5);
    printList(head);

    head = insertAtIndex(head, 10, 2);
    printList(head);

    head = insertAtEnd(head, 50);

    printList(head);


}


void printList(node *ptr)
{
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}



node *insertAtBeg(node *head, int data)
{
    node *newNode = (node *) malloc(sizeof(node));

    newNode -> data = data;
    newNode -> next = head;

    head = newNode;

    return head;
}

node *insertAtIndex(node *head, int data, int index)
{
    node *newNode = (node *) malloc(sizeof(node));

    node *ptr = head;
    int i = 0;

    while (i != index - 1)
    { 
        ptr = ptr -> next;
        i++;
    }
    
    newNode -> data = data;
    newNode->next = ptr->next;
    ptr -> next = newNode;

    return head;
}

node *insertAtEnd(node *head, int data)
{
    node *newNode = (node *) malloc(sizeof(node));

    node *ptr = head;

    while (ptr->next != NULL)
    { 
        ptr = ptr -> next;
    }
    
    newNode -> data = data;
    ptr -> next = newNode;
    newNode->next = NULL;

    return head;
}