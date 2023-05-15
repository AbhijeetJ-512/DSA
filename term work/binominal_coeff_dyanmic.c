// C program for space optimized Dynamic Programming
// Solution of Binomial Coefficient
#include <stdio.h>

int min(int i, int k)
{
    if (i < k)
    {
        return i;
    }
    return k;
}

int bin(int n, int k)
{
    int C[k + 1];
    for (int i = 1; i < k + 1; i++)
    {
        C[i] = 0;
    }
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[k];
}

int main()
{
    int n, k;
    printf("Enter n and k for nCk:\n");
    scanf(" %d%d", &n, &k);
    printf("%d ", bin(n, k));
    return 0;
}
