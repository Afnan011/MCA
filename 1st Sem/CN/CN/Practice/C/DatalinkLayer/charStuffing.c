#include <stdio.h>
#include <string.h>

void main()
{
    int i, j, n, pos;
    char a[10], b[20], ch;

    i = j = 0;

    printf("Enter a string: ");
    scanf("%s", a);
    n = strlen(a);

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos > n)
    {
        printf("Invalid positon! try again: ");
        scanf("%d", &pos);
    }

    printf("Enter character: ");
    scanf(" %c", &ch);

    b[0] = 'd';
    b[1] = 'l';
    b[2] = 'e';
    b[3] = 's';
    b[4] = 't';
    b[5] = 'x';
    j = 6;

    while (i < n)
    {
        if (i == pos - 1)
        {
            b[j] = 'd';
            b[j + 1] = 'l';
            b[j + 2] = 'e';
            b[j + 3] = ch;
            b[j + 4] = 'd';
            b[j + 5] = 'l';
            b[j + 6] = 'e';
            j += 7;
        }

        if (a[i] == 'd' && a[i + 1] == 'l' && a[i + 2] == 'e')
        {
            b[j] = 'd';
            b[j + 1] = 'l';
            b[j + 2] = 'e';
            j += 3;
        }

        b[j] = a[i];
        i++;
        j++;
    }

    b[j] = 'd';
    b[j + 1] = 'l';
    b[j + 2] = 'e';
    b[j + 3] = 'e';
    b[j + 4] = 't';
    b[j + 5] = 'x';
    b[j + 6] = '\0';


    printf("\nFrame after stuffing: ");
    printf("%s\n\n", b);
}