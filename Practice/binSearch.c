#include<stdio.h>

void main()
{
    int a[20], n;
    int pos, flag = 0, item, key;
    int start, mid, end;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the search key: ");
    scanf("%d", &key);

    start = 0;
    end = n-1;
    mid = (start + end)/2;

    while (start <= end)
    {
        if (key == a[mid])
        {
            item = a[mid];
            pos = mid;
            flag = 1;
        }

        if (key < a[mid])
        {
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }

        mid = (start+end)/2;
      
    }
    

    if (flag == 1)
    {
        printf("Element %d found at %d position", item, pos+1);
    }
    else
        printf("Element not found");
    
    
    

}