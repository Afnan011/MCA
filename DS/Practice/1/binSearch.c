#include <stdio.h>

int a[10], n;

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

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    while (ch != 0)
    {
        printf("\nEnter the searach key: ");
        scanf("%d", &target);

        binSearch(target);

        printf("\n\ndo you want to continue: ");
        scanf("%d", &ch);
    }
}