#include <stdio.h>
int a[20];

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int Partition(int A[], int l, int r)
{
    int p = A[l];
    int i = l, j = r + 1;
    do
    {
        do
        {
            i = i + 1;
        } while (A[i] < p);

        do
        {
            j = j - 1;
        } while (A[j] > p);

        if (i < j)
        {
            swap(&A[i], &A[j]);
        }

    } while (i < j);
    
    swap(&A[j], &A[l]);
    return j;
}

void QuickSort(int A[], int l, int r)
{
    if (l < r)
    {
        int s = Partition(A, l, r);
        return QuickSort(A, l, s - 1);
        return QuickSort(A, s + 1, r);
    }
}

void main()
{
    printf("Enter the size of the array:");
    int n, A[20];
    scanf("%d", &n);
    printf("\nEnter the elements to the array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    QuickSort(A, 0, n - 1);
    printf("\nSorted Array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
}