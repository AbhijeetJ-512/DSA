#include <stdio.h>

void factorial(int n)
{
    int product = 1;
    for (int i = 1; i <= n; i++)
    {
        product = product * i; // multiplying the product in a loop
    }
    printf("Output:\n");
    printf("%d", product); // printing the output
}

int main()
{
    int n;
    printf("Enter number:\n");
    scanf("%d", &n); // Entry of number
    factorial(n);    // function call
}
