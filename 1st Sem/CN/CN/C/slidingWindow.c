#include<stdio.h>

void main()
{
    int w, f, i;
    int frames[20];

    printf("Enter Window size: ");
    scanf("%d", &w);

    printf("Enter No. of frames to send: ");
    scanf("%d", &f);

    printf("Enter %d frames: ", f);
    for (i = 1; i <= f; i++)
    {
        scanf("%d", &frames[i]);
    }


    printf("\n\nWith sliding window, the frames are sent in the following manner.");
    printf("\nAfter sliding\n");
    for (i = 1; i <= f; i++)
    {
        if (i % w  == 0)
        {
            printf(" %d ", frames[i]);
            printf("\nAcknowledgement of the above frame sent is received\n");
        }
        else
        {
            printf(" %d ", frames[i]);
        }
    }
         if (f % w != 0)
         {
            printf("\nAcknowledgement of the above frame sent is received\n");
         }
    

}