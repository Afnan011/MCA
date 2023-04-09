#include<stdio.h>

void main()
{
    int a[20], n, item, pos, flag, key;
    int start, end, mid;
    flag = 0;

    printf("Enter size of the aray: ");
    scanf("%d", &n);

    printf("\nEnter %d elemetns: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nEnter the search key: ");
    scanf("%d", &key);

    start = 0;
    end = n-1;
    mid = (start+end)/2;

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
         else
         {
            start = mid + 1;
         }

         mid = (start + end)/2;
            
    }

    if (flag == 1)
    {
        printf("Element %d found at %d position\n", item, pos+1);
    }
    else{
        printf("Element not found");
    }

    

}    