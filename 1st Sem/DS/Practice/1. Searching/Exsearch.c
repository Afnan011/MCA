#include<stdio.h>

int a[10], n;

void linSerach(int target)
{
    int flag, pos;
    flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == target)
        {
            flag = 1;
            pos = i;
            break;
        } 
    }

    if (flag)
    {
        printf("%d element found at %d position\n", target, pos+1);
    }
    else
        printf("%d element not found.\n",target);
    

}

void binSearch(int target)
{
    int flag, pos;
    flag = 0;

    int start = 0;
    int end = n-1;
    int mid = (start + end)/2;

    while (start <= end)
    {
        if (target == a[mid])
        {
            pos = mid;
            flag = 1;
        }

        if (target < a[mid])
        {
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        
        mid = (start + end) / 2;
        
    }
    
    if (flag)
    {
        printf("%d element found at %d position\n", target, pos+1);
    }
    else
        printf("%d element not found.\n",target);

}

void main()
{
    int ch, target;

    printf("\n1.Linear search \n2.Binary search\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    switch (ch)
    {
    case 1:
        printf("Enter %d elements: ", n);
        break;
    case 2:
        printf("Enter %d elements (sorted): ", n);
        break;
    
    default:
        printf("\n\nInvalid choice!\n\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter serach key: ");
    scanf("%d", &target);

    switch (ch)
    {
    case 1:
        linSerach(target);
        break;
    case 2:
        binSearch(target);
        break;
    }
    

}