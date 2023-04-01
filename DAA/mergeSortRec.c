#include<stdio.h>
int a[20];

void main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("\nEnter the elements to the array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    MergeSort(a, 0, n - 1);

    printf("\nSorted Array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
}