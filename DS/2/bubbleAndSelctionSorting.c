#include<stdio.h>

void swap(int *a, int *b);
void display(int a[], int n);
void bubbleSort(int a[], int n);
void selectionSort(int a[], int n);

void main()
{
    int a[20], n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements :", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\narray before sorting: \n");
    display(a, n);

    bubbleSort(a, n);
    printf("\nSorted array using bubble sort(asc): \n");
    display(a, n);
    
    selectionSort(a, n);
    printf("\nSorted array using selection sort(desc): \n");
    display(a, n);


}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int a[], int n)
{
    int j;
    for (int i = 0; i < n; i++)
    {
        j = 0;
        while (j < n-i-1)
        {
            if(a[j] > a[j+1])
                swap(&a[j], &a[j+1]);

            j = j + 1;
        }
        
    }
    
}

void selectionSort(int a[], int n)  
{
    int max;
    for (int i = 0; i < n; i++)
    {
        max = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j] > a[max])
            {
                max = j;
            }
    
        }

     swap(&a[i], &a[max]);   
    }
    
}