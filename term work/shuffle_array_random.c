#include <stdio.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomize(int a[], int n)
{
    srand(time(NULL));
    for (int i = n - 1; i >= 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&a[i], &a[j]);
    }
}

void main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    randomize(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}