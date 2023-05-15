#include <stdio.h>
#include <stdlib.h>

typedef struct JOB
{
    char j;
    int time;
    int profit;
} job;

void sort(job a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n - i - 1; k++)
        {
            if (a[k].profit < a[k + 1].profit)
            {
                job temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
            }
        }
    }
}

void max_profit(job arr[], int n, int x)
{
    int max = -1, c = 0;
    printf("JOb should be:\n");
    for (int i = 0; i < x && i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j].profit > max && arr[j].time >= i)
            {
                max = arr[j].profit;
                c = j;
            }
        }
        max = -1;
        arr[c].profit = 0;
        printf("%c ", arr[c].j);
    }
}

void main()
{
    job arr[] = {{'a', 2, 95},
                 {'b', 1, 23},
                 {'c', 2, 17},
                 {'d', 4, 35},
                 {'e', 3, 15}};
    int n = sizeof(arr) / sizeof(job);
    sort(arr, n);
    printf("enter deadline works:\n");
    int x;
    scanf("%d", &x);
    max_profit(arr, n, x);
}