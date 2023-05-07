#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int coef;
    int expo;
    struct Node *next;
}node;

node *attach(int coef1, int expo1, node *start)
{
    node *temp, *dstart;
    temp = (node *)malloc(sizeof(node));
    temp->coef = coef1;
    temp->expo = expo1;
    dstart = start->next;
    
    while (dstart->next != start)
        dstart = dstart->next; // the great inner meaning
    
    dstart->next = temp;
    temp->next = start;
    
    return start;
}

node *readpoly(node *start)
{
    char ch = 'y';
    int coef, expo;

    while (ch == 'y')
    {
        printf("Enter Coefficient and Exponent\n");
        scanf("%d%d", &coef, &expo);
        start = attach(coef, expo, start);
        printf("Do you wish to enter any more enter(Y/N)\n");
        scanf(" %c", &ch);
    }
    return start;
}

int compare(int a, int b)
{
    if (a < b)
        return -1;
    if (a == b)
        return 0;
    if (a > b)
        return 1;
}

node *polyadd(node *startA, node *startB, node *startC)
{
    int sum;
    node *dstartA, *dstartB;
    dstartA = startA->next;
    dstartB = startB->next;
    
    while (dstartA != startA && dstartB != startB)
    {
        switch (compare(dstartA->expo, dstartB->expo))
        {
        case 1:
            startC = attach(dstartA->coef, dstartA->expo, startC);
            dstartA = dstartA->next;
            break;
        case 0:
            sum = dstartA->coef + dstartB->coef;
            startC = attach(sum, dstartA->expo, startC);
            dstartA = dstartA->next;
            dstartB = dstartB->next;
            break;
        case -1:
            startC = attach(dstartB->coef, dstartB->expo, startC);
            dstartB = dstartB->next;
            break;
        }
    }
    while (dstartA != startA)
    {
        startC = attach(dstartA->coef, dstartA->expo, startC);
        dstartA = dstartA->next;
    }
    while (dstartB != startB)
    {
        startC = attach(dstartB->coef, dstartB->expo, startC);
        dstartB = dstartB->next;
    }
    return startC;
}

void main()
{
    node *startA, *startB, *startC, *dstartA, *dstartB, *dstartC;
    startA = (node*)malloc(sizeof(node));
    startB = (node*)malloc(sizeof(node));
    startC = (node*)malloc(sizeof(node));

    startA->next = startA; // critical
    startB->next = startB;
    startC->next = startC;

    printf("Reading Polynomial A\n");
    startA = readpoly(startA);

    printf("Reading Polynomial B\n");
    startB = readpoly(startB);

    dstartA = startA->next;
    dstartB = startB->next;
    printf("Polynomial A\n");
    while (dstartA != startA)
    {
        printf("%d^%d", dstartA->coef, dstartA->expo);
        dstartA = dstartA->next; // critical
        if (dstartA != startA)
            printf("+");
    }

    printf("\nPolynomial B\n");
    while (dstartB != startB)
    {
        printf("%d^%d", dstartB->coef, dstartB->expo);
        dstartB = dstartB->next;
        if (dstartB != startB)
            printf("+");
    }
    
    startC = polyadd(startA, startB, startC);
    dstartC = startC->next;
    printf("\nPolynomial C\n");
    
    while (dstartC != startC)
    {
        printf("%d^%d", dstartC->coef, dstartC->expo);
        dstartC = dstartC->next;
        if (dstartC != startC)
            printf("+");
    }

}