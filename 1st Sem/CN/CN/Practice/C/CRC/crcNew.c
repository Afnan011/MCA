#include<stdio.h>

void divide(int dwLen, int gLen, int data[50], int gen[50]);

void main()
{
    int dwLen, cwLen, gLen, i, j, error;
    int dw[50], cw[50], gen[50];
    int rCode[50];

    printf("\n--------------Transmitter Side--------------\n");

    printf("Enter data word length: ");
    scanf("%d", &dwLen);

    printf("Enter dataword: ");
    for (i = 0; i < dwLen; i++)
    {
        scanf("%d", &dw[i]);
    }

    printf("Enter generator length: ");
    scanf("%d", &gLen);

    printf("Enter generator: ");
    for (i = 0; i < gLen; i++)
    {
        scanf("%d", &gen[i]);
    }


    cwLen = dwLen + (gLen-1);

    for (i = dwLen; i < cwLen; i++)
    {
        dw[i] = 0;
    }

    printf("\nData word with zeros appended: ");
    for (i = 0; i < cwLen; i++)
    {
        printf(" %d ", dw[i]);
    }

    for (i = 0; i < cwLen; i++)
    {
        cw[i] = dw[i];
    }

    divide(dwLen, gLen, dw, gen);

    printf("\nThe Remainder is: ");
    for (i = dwLen; i < cwLen; i++)
    {
        printf(" %d ", dw[i]);    
    }

    for (i = dwLen; i < cwLen; i++)
    {
        cw[i] = dw[i];    
    }

    printf("\nData word to be transmitted is: ");
    for (i = 0; i < cwLen; i++)
    {
        printf(" %d ", cw[i]);
    }

    printf("\n--------------Reciever Side--------------\n");

    printf("Enter recived code word: ");
    for (i = 0; i < cwLen; i++)
    {
        scanf("%d", &rCode[i]);
    }

    divide(dwLen, gLen, rCode, gen);

    printf("\nThe Remainder is: ");
    for (i = dwLen; i < cwLen; i++)
    {
        printf(" %d ", rCode[i]);    
    }

    error = 0;
    for (i = dwLen; i < cwLen; i++)
    {
        if(rCode[i] == 1)
            error = 1;    
    }

    if(error)
        printf("\n\nHas error\n");
    else
        printf("\n\nHas NO error\n");

}


void divide(int dwLen, int gLen, int data[50], int gen[50])
{
    int i, j;
    for (i = 0; i < dwLen; i++)
    {   
        if (data[i] == 0)
        {
            for (j = 0; j < gLen; j++)
            {
                data[j+i] = data[j+i] ^ 0;
            }
        }
        else
        {
            for (j = 0; j < gLen; j++)
            {
                data[j+i] = data[j+i] ^ gen[j];
            }
        }
        
    }
    
}