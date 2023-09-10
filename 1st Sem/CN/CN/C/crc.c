#include <stdio.h>

void divide(int dwLen, int gLen, int data[50], int gen[50]);

void main()
{
    int dwLen, cwLen, gLen, error, i;
    int dw[50], cw[50], gen[50];
    int rCw[50];

    printf("\n=============Transmitter side=============\n");

    printf("Enter length of the data word: ");
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

    cwLen = dwLen + (gLen - 1);

    // append zeros
    for (i = dwLen; i < cwLen; i++)
    {
        dw[i] = 0;
    }

    printf("\nData word after appending zeros: ");
    for (i = 0; i < cwLen; i++)
    {
        printf("%d ", dw[i]);
    }

    // copy dataword into codeword
    for (i = 0; i < cwLen; i++)
    {
        cw[i] = dw[i];
    }

    divide(dwLen, gLen, dw, gen);

    // remainder
    printf("\nRemainder is : ");
    for (i = dwLen; i < cwLen; i++)
    {
        printf("%d ", dw[i]);
    }

    // append rem to code word
    for (i = dwLen; i < cwLen; i++)
    {
        cw[i] = dw[i];
    }

    printf("\nThe code word to be transmitted is : ");
    for (i = 0; i < cwLen; i++)
    {
        printf(" %d ", cw[i]);
    }

    printf("\n=============Reciever side=============\n");

    printf("Enter recieved code word: ");
    for (i = 0; i < cwLen; i++)
    {
        scanf("%d", &rCw[i]);
    }

    divide(dwLen, gLen, rCw, gen);

    printf("\nRemainder is : ");
    for (i = dwLen; i < cwLen; i++)
    {
        printf("%d ", rCw[i]);
    }

    error = 0;

    for (i = dwLen; i < cwLen; i++)
    {
        if (rCw[i] == 1)
        {
            error = 1;
        }
    }

    if (error)
    {
        printf("\n\nHas error\n\n");
    }
    else
    {
        printf("\n\nNO error\n\n");
    }
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
                data[j + i] = data[j + i] ^ 0;
            }
        }
        else
        {
            for (j = 0; j < gLen; j++)
            {
                data[j + i] = data[j + i] ^ gen[j];
            }
        }
    }
}