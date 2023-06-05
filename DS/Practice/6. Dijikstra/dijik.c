#include<stdio.h>

int cost[10][10], d[10], p[10], v[10], n;

void dijik(int s)
{
    int i, j, min, u, count = 1;

    for(i = 0; i < n; i++)
    {
        v[i] = 0;
        p[i] = s;
        d[i] = cost[s][i];
    }
    v[s] = 1;

    while (count < n)
    { 
        u = -1;
        min = 99;

        for (i = 0; i < n; i++)
        {
            if (v[i] == 0 && d[i] < min) 
            {
                min = d[i];
                u = i;
            }
        }
        v[u] = 1;

        for (i = 0; i < n; i++)
        {
            if (v[i] == 0 && d[u]+cost[u][i] < d[i])
            {
                d[i] = d[u]+cost[u][i];
                p[i] = u;
            }
        }
        count = count + 1;
    }
}

void printPath(int src)
{
    for (int dest = 0; dest < n; dest++)
    {
        int i = dest;
        while(i != src)
        {
            printf("%d <--", i);
            i = p[i];
        }
        printf("%d = %d\n", i, d[dest]);
    }
    
}

void main()
{
    int i, j, s;

    printf("Enter no of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("\n\ncost adjacency matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
    

    dijik(s);

    printf("The path is : ");
    printPath(s);
}