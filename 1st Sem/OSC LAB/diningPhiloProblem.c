// C program to simulate the working of dining philosophers problem for 5 philosophers 
// and with maximum 2 eaters

#include <stdio.h>
#define NP 5			//NP->total number of plates

void forks(int eatP);
void eat1(int eatP);

int isNeighbor(int eatP1, int eatP2);
void eat2();

void main()
{
	int wEat, eatP;		//wEat -> no. of philosophers wants to eat
	//eatP -> which particular philoshopher is eating

	printf("Enter how many philosophers wants to eat:");
	scanf("%d", &wEat);
	if (wEat == 1)
	{
		printf("\nEnter which philosopher wants eat(0-4 values):");
		scanf("%d", &eatP);
		eat1(eatP);
	}
	else if (wEat == 2)
	{
		eat2();
	}
	else
	{
		printf("\nDeadlock state");
	}
}


void forks(int eatP)
{
	int frk0, frk1;
	frk0 = eatP;

	if (eatP == 0)
		frk1 = NP - 1;

	else
		frk1 = eatP - 1;

	printf("\n%d can use Fork%d and Fork%d", eatP, frk0, frk1);
}

int isNeighbor(int eatP1, int eatP2){
	
	if (eatP2 == eatP1 + 1 || eatP2 == eatP1 - 1)
		return 1;

	else if(eatP2 == 0 && eatP1 == NP - 1 || eatP1 == 0 && eatP2 == NP - 1)
		return 1;

	else	
		return 0;
	
}

void eat1(int eatP)
{
	printf("\nPhilosopher %d is allowed to eat", eatP);
	forks(eatP);
}

void eat2()
{
	int eatP1, eatP2;

	printf("\nEnter which 2 different philosphers wants eat(0-4):");
	printf("\nPhilosopher:");
	scanf("%d", &eatP1);

	printf("\nPhilosopher:");
	scanf("%d", &eatP2);

	if (isNeighbor(eatP1, eatP2) == 1)
	{
		printf("\nAt a time these two philosophers cant eat as they are neighbors");
		eat1(eatP1);
		printf("\n%d is waiting", eatP2);
		printf("\n%d is completed eating", eatP1);
		eat1(eatP2);
	}
	else
	{
		eat1(eatP1);
		eat1(eatP2);
	}
}
