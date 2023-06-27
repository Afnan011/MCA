#include<stdio.h>
#include<string.h>

void main()
{
    int a[20], b[30];
    int i, j, k;
    int n, count;

    printf("Enter frame size:");
    scanf("%d", &n);

    printf("\nEnter input frame: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    

    i = 0; 
    j = 0;
    count = 1;

    while (i < n)
    {
        
        if (a[i] == 1)
        {
            b[j] = a[i];
            for (k = i+1; a[k] == 1 && k < n && count < 5; k++)
            {
                j++;
                b[j] = a[k];
                count++;
                if (count == 5)
                {
                    j++;
                    b[j] = 0;
                    count = 0;
                }
                i = k;
                
            }
            
        }
        else
        {
            b[j] = a[i];
        }

        i++;
        j++;
    
    }
    
    printf("After stuffing: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d", b[i]);
    }
    

}