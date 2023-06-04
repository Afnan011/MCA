#include<stdio.h>

void swap(int *a, int *b);
void display(int a[], int n);

void bubbleSort(int a[], int n);
void selectSort(int a[], int n);

void main()
{
    int a[10], n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nArray before sorting: \n");
    display(a, n);

    bubbleSort(a, n);
    printf("\nArray after sorting with bubble Sort(Asc): \n");
    display(a, n);
    
    selectSort(a, n);
    printf("\nArray after sorting with Selection Sort(Desc): \n");
    display(a, n);

}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
}

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (a[j] > a[j+1])
                swap(&a[j], &a[j+1]); 
        }
    }   
}

void selectSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int max = i;
        for (int j = i+1; j < n; j++)
        {
            if(a[j] > a[max])
                max = j;
        }

        swap(&a[i], &a[max]);
    }
}