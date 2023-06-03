// C program to simulate the working of consumer producer problem in operating system

#include <stdio.h>
#define Maxf 4			//Max items+ that can be produced

int plate[Maxf];
int front = -1;
int rear = -1;

void produce(int quan);
void consume();

void main()
{
	int quan, ch;

	do
	{
		printf("\n1.Produce \n2.Consume \n3.Exit");
		printf("\nEnter what operation to perform: ");
		scanf("%d", &ch);
		switch (ch)
		{

		case 1:
			printf("\nEnter how much quantity want to produce:");
			scanf("%d", &quan);
			produce(quan);
			break;

		case 2:
			consume();
			break;

		case 3:
			printf("\nExiting");
			break;

		default:
			printf("\nEnter a valid choice");
		}

	} while (ch != 3);
}

void produce(int quan)
{

	if ((front == 0 && rear == Maxf - 1) || (front > rear))
	{
		printf("\nCannot produce");
		return;
	}

	if (front == -1)
		front = 0;

	rear = (rear + 1) % Maxf;
	plate[rear] = quan;
	printf("\n%d items are produced and ready to consume", quan);
}

void consume()
{
	int food;
	if (front == -1 && rear == -1)
	{
		printf("\nPlate is empty");
		return;
	}

	food = plate[front];

	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
		front = (front + 1) % Maxf;
		
	printf("\n%d items are consumed", food);
}
