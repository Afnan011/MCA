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
        printf("Enter search key: ");
        scanf("%d", &target);

        linSearch(target);

        printf("\n\ndo you want to continue: ");
        scanf("%d", &ch);
    }
}