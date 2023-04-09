#include<stdio.h>

void main()
{
    int a[20], n;
    int pos, flag = 0, item, key;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the search key: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            pos = i;
            item = a[i];
            flag = 1;
        }
        
    }

    if (flag == 1)
    {
        printf("Element %d found at %d position", item, pos+1);
    }
    else
        printf("Element not found");
    
    
    

}