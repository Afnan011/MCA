    #include <stdio.h>
    #include <stdlib.h>
    int wt[10][10] = {
        {0, 3, 99, 99, 6, 5},
        {3, 0, 1, 99, 99, 4},
        {99, 1, 0, 6, 99, 4},
        {99, 99, 6, 0, 8, 5},
        {6, 99, 99, 5, 0, 2},
        {5, 4, 4, 5, 2, 0}};
    int n, mincost, v1 = 0, v2 = 0;
    void findMin() // finding the edge having minimum weight.
    {
        int edgewt = 99, i, j;
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (wt[i][j] > 0 && wt[i][j] < edgewt)
                {
                    edgewt = wt[i][j];
                    v1 = i;
                    v2 = j;
                }
            }
        }
    }

    void doUnion(int root[], int v1, int v2)
    {
        int temp, i;
        temp = root[v2];
        for (i = 0; i < n; i++)
        {
            if (root[i] == temp)
            {
                root[i] = root[v1];
            }
        }
    }
    void kruskal()
    {
        int i, edgewt;
        int root[n + 1];
        for (i = 0; i <= n; i++)
            root[i] = i;
        printf("\nEdges of min-cost spanning tree are");
        i = 0;
        while (i != n - 1)
        {
            findMin(); // updates v1 & v2 with vertices of edge with minimum weight
            edgewt = wt[v1][v2];
            wt[v1][v2] = wt[v2][v1] = 0; // supresses selection of same edge on next time.
            if (root[v1] != root[v2])
            {
                printf("\n(%d ,%d)", v1, v2);
                doUnion(root, v1, v2);
                mincost += edgewt;
                i++;
            }
        }
        printf("\nCost of min-cost spanning tree =%d ", mincost);
    }

    void main()
    {
        int i, j;
        printf("Enter the number of vertices");
        scanf("%d", &n);
        printf("Enter the undirected graph as adjacency matrix\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%d\t", wt[i][j]);
            }
            printf("\n");
        }
        kruskal();
    }