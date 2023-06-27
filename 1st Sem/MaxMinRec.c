#include <stdio.h>
int a[30];

void MaxMin(int i, int j, int *max, int *min)
{
    if (i == j)
    {
        *max = *min = a[i];
    }
    else if (i == j-1)
    {
        if (a[i] < a[j])
        {
            *max = a[j];
            *min = a[i];
        }
        else{
            *max = a[i];
            *min = a[j];
        }
    }
    else
    {
        int mid = (i + j) / 2;
        int max1, min1;
        
        MaxMin(i, mid, max, min);
        MaxMin(mid+1, j, &max1, &min1);

        if (*max < max1)
            *max = max1;
        if (*min > min1)
            *min = min1;

    }
}

void main()
{
    int n, max, min;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the array elements: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int i = 0;
    int j = n-1;
    MaxMin(i, j, &max, &min);

    printf("Max = %d\n", max);
    printf("Min = %d\n", min);

}