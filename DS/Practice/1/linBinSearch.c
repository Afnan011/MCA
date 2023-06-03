#include <stdio.h>

int a[10], n;

void linSearch(int target)
{
    int flag, pos;
    flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == target)
        {
            pos = i;
            flag = 1;
            break;
        }
    }

    if (flag == 1)
        printf("%d found at %d position", target, pos + 1);
    else
        printf("%d not found in the list", target);
}

void binSearch(int target)
{
    int pos, flag;
    flag = 0;

    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;

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
        else
        {
            start = mid + 1;
        }

        mid = (start + end) / 2;
    }

    if (flag == 1)
        printf("%d found at %d position", target, pos + 1);
    else
        printf("%d not found in the list", target);
}

void main()
{
    int target, ch = 1;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("\n1.Linear Search \n2.Binary Search");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("\nEnter %d elements: ", n);
        break;

    case 2:
        printf("\nEnter %d elements(sorted): ", n);
        break;

    default:
        printf("\n\nInvalid choice\n\n");
        return;
    }

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nEnter the searach key: ");
    scanf("%d", &target);

    switch (ch)
    {
    case 1:
        linSearch(target);
        break;

    case 2:
        binSearch(target);
        break;
        ;
    }
}