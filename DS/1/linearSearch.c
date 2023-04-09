#include<stdio.h>

void main()
{
    int a[20], n, item, pos, flag, key;
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
    
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            flag = 1;
            item = a[i];
            pos = i;
        }
        
    }
    
    if (flag == 1)
    {
        printf("Element %d found at %d position\n", item, pos+1);
    }
    else{
        printf("Element not found.");
    }
    
}