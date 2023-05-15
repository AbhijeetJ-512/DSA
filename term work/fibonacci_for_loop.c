#include <stdio.h>

int fibo(int a[], int n)
{
    for (int i = 2; i < n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
}

void main()
{
    int n;
    printf("Enter number for fibonacci:\n");
    scanf("%d", &n);
    int a[n];
    a[0] = 0;
    a[1] = 1;
    fibo(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}