#include<stdio.h>
#define MAX 3

void display();
void Qinsert(int);
void Qdelete();

int queue[MAX];
int front = -1;
int rear = -1;

void main()
{
    int ch, item;

    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: printf("\nEnter the element to insert: ");
                    scanf("%d", &item);
                    Qinsert(item);
                    break;

            case 2: Qdelete();
                    break;

            case 3: display();
                    break;

            case 4: printf("\nExiting...\n");
                    break;

            default: printf("Enter the valid choice!");                        
        }

    }while(ch != 4);

}

void Qinsert(int item)
{
    if(rear == MAX-1)
    {
        printf("\nQueue is full!, Failed to insert %d", item);
        return;
    }

    if(front == -1)
        front = 0;
    
    rear = rear + 1;
    queue[rear]  = item;

}

void Qdelete()
{
    if( (front == -1) || (front > rear))
    {
        printf("\nQueue is Empty!\n");
        return;
    }

    
    int item = queue[front];
    front = front + 1;

    printf("\n%d removed from the queue\n", item);

}

void display()
{
    if( (front == -1) || (front > rear))
    {
        printf("\nQueue is Empty!\n");
        return;
    }

    for(int i = front; i<= rear; i++)
    {
        printf(" %d ", queue[i]);
    }
    printf("\n");
}