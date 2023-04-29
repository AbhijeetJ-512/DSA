#include <stdio.h>
#include <stdlib.h>
void main()
{
    int *a;
    int n;
    printf("Enter the size of array:");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    free(a);
    printf("Freed array\n");
}