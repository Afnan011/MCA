#include <stdio.h>

int *compare(int a[], int b[], int n)
{
    int res[2];

    res[0] = res[1] = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
            res[0] += 1;

        else if (a[i] < b[i])
            res[1] += 1;
    }

    return res;
}

int main()
{
    int a[100], b[100];
    int n = 3;
    int *res;

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    res = compare(a, b, n);

    for (int i = 0; i < 2; i++)
        printf("%d ", *res);

    return 0;
}