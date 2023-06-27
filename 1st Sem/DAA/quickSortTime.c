#include <stdio.h>
#include<time.h>

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
        QuickSort(A, l, s - 1);
        QuickSort(A, s + 1, r);
    }
}
void main()
{
    int rn = 5000;

    clock_t start, end;
    double cpu_time_used;

    int A[20],arr[5000];
    printf("Enter the size of the array:");
    int n;
    scanf("%d", &n);
    printf("\nEnter the elements to the array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    start = clock();
    QuickSort(A, 0, n - 1);
    end = clock();
    
    printf("\nSorted Array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime Efficiency for the user Input: %f\n", cpu_time_used);


    //time efficiency
    for (int i = 0; i < rn; i++) {
        arr[i] = rand();
    }
    /*
    for (int i = 0; i < rn; i++) {
        printf(" %d ",arr[i]);
    }
    */

    start = clock();
    QuickSort(arr,0,rn-1);
    end = clock();

    /*
    printf("\nSorted random Array:");
    for (int i = 0; i < rn; i++) {
        printf(" %d ",arr[i]);
    }
    */
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Average case time efficiency of random input of %d numbers is : %f\n", rn, cpu_time_used);
}