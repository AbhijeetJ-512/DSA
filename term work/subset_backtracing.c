#include <stdio.h>
#include <time.h>

void rec(int a[], int b[], int m, int n, int k)
{
    for (int i = 0; i < k; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    for (int i = m; i < n; i++)
    {
        b[k] = a[i];
        rec(a, b, i + 1, n, k + 1);
    }
}

int main()
{
    int a[4];
    printf("how many numbers in array:\n");
    int n;
    scanf("%d", &n);
    printf("Enter array elemnts:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int b[n];
    printf("subsets:\n");
    rec(a, b, 0, n, 0);
}