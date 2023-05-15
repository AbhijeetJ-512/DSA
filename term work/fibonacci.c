#include <stdio.h>
#include <time.h>
int fibonacci_series(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fibonacci_series(n - 1) + fibonacci_series(n - 2); // calling the same function(recursion)
}

void main()
{
    clock_t start, stop;
    int n;
    printf("Enter number for fibonaci series:\n");
    scanf("%d", &n); // input
    start = clock();
    n = fibonacci_series(n); // function call
    stop = clock();
    float time = (float)(stop - start) / CLOCKS_PER_SEC;
    printf("%0.5f\n", time);
    printf("The output is:%d\n", n); // output
}