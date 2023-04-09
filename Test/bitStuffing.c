#include<stdio.h>

void main()
{
    int a[20], b[20], i, j, k, count, n;

    printf("Enter frame length: ");
    scanf("%d", &n);

    printf("Enter input frame (0's and 1's only: )");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }


    i = 0, j = 0, count = 1;
    while (i < n)
    {
        
        if(a[i] == 1)
        {
            b[j] = a[i];
            for (k = i+1; a[k] == 1 && k<n && count < 5; k++)
            {
                j++;
                count++;
                b[j] = a[k];

                if(count == 5)
                {
                    j++;
                    b[j] = 0;
                    count = 0;
                }

                i = k;
            }
            

        }
        else{
            b[j] = a[i];
        }

        i++;
        j++;
    }
    
    for(i = 0; i<n; i++)
        printf(" %d ", b[i]);

}