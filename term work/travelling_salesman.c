#include <stdio.h>

void takeInput(int ary[10][10], int n, int completed[10])
{
    int i, j;

    printf("\nEnter the Cost Matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &ary[i][j]);

        completed[i] = 0;
    }

    printf("\n\nThe cost list is:");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("\t%d", ary[i][j]);
        }
    }
}

void mincost(int ary[10][10], int n, int completed[10], int city, int *cost)
{
    int i, ncity;

    completed[city] = 1;
    printf("%d--->", city + 1);

    ncity = least(ary, n, completed, city, cost);

    if (ncity == 999)
    {
        ncity = 0;
        printf("%d", ncity + 1);
        (*cost) += ary[city][ncity];
        return; // base case for backtracking
    }

    mincost(ary, n, completed, ncity, cost);
}

int least(int ary[10][10], int n, int completed[10], int c, int *cost)
{
    int i, nc = 999;
    int min = 999, kmin;

    for (i = 0; i < n; i++)
    {
        if ((ary[c][i] != 0) && (completed[i] == 0))
        {
            if (ary[c][i] + ary[i][c] < min)
            {
                min = ary[c][i] + ary[i][c];
                kmin = ary[c][i];
                nc = i;
            }
        }
    }
    if (min != 999)
        (*cost) += kmin;
    return nc;
}

int main()
{
    int ary[10][10];
    int n;
    int cost = 0;
    int completed[10];
    printf("Enter the number of villages: ");
    scanf("%d", &n);
    takeInput(ary, n, completed);
    printf("\nThe Path is:\n");
    mincost(ary, n, completed, 0, &cost); // passing 0 because starting vertex
    printf("\n\nMinimum cost is %d\n ", cost);
    return 0;
}
