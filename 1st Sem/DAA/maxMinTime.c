#include <stdio.h>
#include <time.h>

int a[30], arr[5000];

void MaxMin(int i, int j, int *max, int *min)
{
    if (i == j)
    {
        *max = *min = a[i];
    }
    else if (i == j - 1)
    {
        if (a[i] < a[j])
        {
            *max = a[j];
            *min = a[i];
        }
        else
        {
            *max = a[i];
            *min = a[j];
        }
    }
    else
    {
        int mid = (i + j) / 2;
        int max1, min1;

        MaxMin(i, mid, max, min);
        MaxMin(mid + 1, j, &max1, &min1);

        if (*max < max1)
            *max = max1;
        if (*min > min1)
            *min = min1;
    }
}

void main()
{
    int n, max, min, rn = 5000;

    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the array elements: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int i = 0;
    int j = n - 1;

    start = clock();
    MaxMin(i, j, &max, &min);
    end = clock();

    printf("Max = %d\n", max);
    printf("Min = %d\n", min);

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime Efficiency for the user Input: %f\n", cpu_time_used);
    
    //time efficiency
    for (int i = 0; i < rn; i++)
    {
        arr[i] = rand();
    }
    /*
    for (int i = 0; i < rn; i++)
    {
        printf(" %d ",arr[i]);
    }
    */
    start = clock();
    MaxMin(0, rn - 1, &max, &min);
    end = clock();
    
    printf("Max = %d\n", max);
    printf("Min = %d\n", min);

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Average case, Best case and Worst case time efficiency for Random input of %d input is : %f\n", rn, cpu_time_used);
}