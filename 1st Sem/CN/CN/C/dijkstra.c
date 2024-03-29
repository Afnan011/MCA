#include<stdio.h>

int cost[10][10], d[10], p[10], v[10], n;

void dijkstra(int s)
{
    int i, j, u, min, count =1;

    for (i = 0; i < n; i++)
    {
        v[i] = 0;
        p[i] = s;
        d[i] = cost[s][i];
    }
    v[s] = 1;

    while (count < n)
    {
        int min = 99;
        int u = -1;

        for (i = 0; i < n; i++)
        {
            if (v[i]==0 && d[i] < min)
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

        count++;
   
    }
    
    
}

void printPath(int src)
{
    for (int dest = 0; dest < n; dest++)
    {
        int i = dest;
        while (i != src)
        {
            printf("%d<-- ", i);
            i = p[i];
        }

        printf("%d = %d\n", i, d[dest]);
    }
    
}

void main()
{
 int i, j, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix: \n");
    for (i = 0; i < n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("\nEnter source: ");
    scanf("%d", &s);

    printf("\nThe cost adjacency matrix is: \n");
        for (i = 0; i < n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
    
    dijkstra(s);

    int flag = 0;
    for (i = 0; i < n; i++)
    {
        if (d[i] == 99)
            flag = 1;   
    }

    if (flag)
    {
        printf("\nPlease provide a valid Weighted connected graph.");
        return;
    }
    
    printf("\nPath is: \n");
    printPath(s);
}