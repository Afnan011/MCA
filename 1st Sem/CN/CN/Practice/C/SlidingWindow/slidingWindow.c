#include<stdio.h>

void main()
{
    int i, f, w, frames[20];

    printf("Enter window size: ");
    scanf("%d", &w);

    printf("Enter no. of frames to send: ");
    scanf("%d", &f);

    printf("Enter %d frames: ", f);
    for (i = 1; i <= f; i++)
    {
        scanf("%d", &frames[i]);
    }


    for (i = 1; i <= f; i++)
    {
        if (i % w == 0)
        {
            printf(" %d ", frames[i]);
            printf("\nAck of above frame sent is recieved.\n");
        }
        else
            printf(" %d ", frames[i]);
        
    }

    if(f%w != 0)
        printf("\nAck of above frame sent is recieved.\n");
    
    

}