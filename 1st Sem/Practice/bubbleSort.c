//Bubble and Selection sort
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

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nArray before sorting\n");
    display(a, n);

    printf("Array after sorting using bubble sort(Ascending order)\n");
    bubbleSort(a, n);
    display(a, n);
    
    printf("Array after sorting using selection sort(Descending order)\n");
    selectionSort(a, n);
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
    int j;
    for (int i = 0; i < n; i++)
    {
        j=0;
        while (j < n-i-1)
        {
            if(a[j] > a[j+1])
            {
                swap(&a[j], &a[j+1]);
            }
            j = j + 1;
        }
        
    }

}

void selectionSort(int a[], int n)  
{
    for (int i = 0; i < n; i++)
    {
        int max = i;
        for (int j = i+1; j < n; j++)
        {
            if(a[j] > a[max])
            {
                max = j;
            }
        }
        swap(&a[i], &a[max]);
        
    }
    
}