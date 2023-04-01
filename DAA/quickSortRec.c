#include <stdio.h>

int a[20];

void swap(int *i, int *j);
int Partition(int a[], int l, int r);
void QuickSort(int a[], int l, int r);

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

    QuickSort(a, 0, n - 1);

    printf("\nSorted Array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
}

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int Partition(int a[], int l, int r)
{
    int p = a[l];
    int i = l, j = r + 1;
    do
    {
        do
        { 
            i = i + 1;
        }while (a[i] < p);
        
        do
        {
            j = j - 1;
        } while (a[j] > p);

        if (i < j)
        {
            swap(&a[i], &a[j]);
        }

    } while (i < j);

    swap(&a[j], &a[l]);
    return j;
}

void QuickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int j = Partition(a, l, r);
        QuickSort(a, l, j - 1);
        QuickSort(a, j + 1, r);
    }
}