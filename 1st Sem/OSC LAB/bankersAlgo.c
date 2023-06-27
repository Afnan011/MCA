#include <stdio.h>
#include <stdbool.h>

void main()
{
    int i, j, m, n;
    int seq[10], allocMax[10];
    int need[10][10], avail[10][10];
    // int alloc[10][10], max[10][10], need[10][10], avail[10][10];
    bool state = false;

    printf("Enter number of Processes : ");
    scanf("%d", &n);
    printf("Enter number of Resource types : ");
    scanf("%d", &m);

    int alloc[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}};

    int max[5][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3},
    };

    // printf("Enter allocation for each processes: \n");
    //
    //
    /* Input data into  alloc and max and need matrix */
    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j < m; j++)
    //     {
    //         //printf("Enter data in P[%d] and R[%d]: ", i, j);
    //         scanf("%d", &alloc[i][j]);
    //     }
    // }

    // printf("Enter Max value for each processes: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            //printf("Enter data in P[%d] and R[%d]: ", i, j);
            // scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (i = 0; i < n; i++)
    {
        int temp = 0;
        temp += alloc[i][0];
        allocMax[i] = temp;
    }
    


    /* Display the matrix */

    printf("\nAllocation \t Max \t\t Need\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf(" %d ", alloc[i][j]);
        }

        printf("\t");
        for (j = 0; j < m; j++)
        {
            printf(" %d ", max[i][j]);
        }

        printf("\t");
        for (j = 0; j < m; j++)
        {
            printf(" %d ", need[i][j]);
        }

        printf("\t");
        for (j = 0; j < m; j++)
        {
            printf(" %d ", allocMax[i]);
        }
        printf("\n");
    }

}