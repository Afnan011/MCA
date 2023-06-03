#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

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

        case 3: deleteFromBeg();
                break;

        case 4: deleteFromEnd();
                break;

        case 5: 
                printf("\nEnter position to be deleted: ");
                scanf("%d", &pos);
                deleteFromPos(pos);
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