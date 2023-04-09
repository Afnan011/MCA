#include <stdio.h>

int main()
{
    
    int n, count, max;
    scanf("%d", &n);

    count = max = 0;
    while (n > 0)
    {
        if (n%2 == 1)
        {
            count++;
            if (count > max)
                max = count;
        }
        else{
            count = 0;
        }       
        n = n / 2;
    }


printf("%d", max);
    return 0;
}
