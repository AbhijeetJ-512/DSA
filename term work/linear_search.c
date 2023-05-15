#include <stdio.h>

void linear_search(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++) // loop
    {
        if (arr[i] == k) // iterates the same line n times
        {
            printf("Search successful");
            return;
        }
    }
    printf("Search unsuccessfull");
}

int main()
{
    int arr[] = {2, 4, 12, 34, 1, 56, 0, 465, 4};
    int n = sizeof(arr) / sizeof(int);
    printf("Enter search element:\n");
    int k;
    scanf("%d", &k);
    linear_search(arr, n, k);
}