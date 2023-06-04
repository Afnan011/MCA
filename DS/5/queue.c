#include<stdio.h>
#define MAX 3

int isEmpty();
void Qinsert(int);
void Qdelete();
void display();

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
            case 1: printf("\nEnter item to be inserted : ");
                    scanf("%d", &item);
                    Qinsert(item);
                    break;
                    
            case 2: Qdelete();
                    break;
                    
            case 3: display();
                    break;
                    
            case 4: printf("\nExiting...\n");
                    break;
                   
            default: printf("\ninvalid choice\n");
                     
        }
        
    }while(ch != 4);
    
}

int isEmpty()
{
    if ((front == -1) || (front > rear))
    {
        return 1;
    }
  
    return 0;
        
}

void display()
{
    if(isEmpty())
    {
        printf("\nQueue is Empty!\n");
        return;
    }
    
    for (int i = front; i <= rear; i++)
    {
        printf(" %d ", queue[i]);
    }
    printf("\n");
}

void Qinsert(int item)
{

    if (rear == MAX-1)
    {
        printf("\nQueue is Full! Failed to insert %d \n", item);
        return;
    }
    
    if (front == -1)
    {
        front = 0;
    }
    
    rear = rear + 1;
    queue[rear] = item; 
}

void Qdelete()
{

    if(isEmpty())
    {
        printf("\nQueue is Empty!\n");
        return;
    }
    
    int item = queue[front];
    front = front + 1;
    
    printf("\n%d removed from the queue\n" , item);
}

