#include <stdio.h>

int max_number(int arr[], int n)
{
    if (n < 0)
    {
        return 0; // return 0 if arr index is less then 0
    }
    int max = max_number(arr, n - 1); // calling own same function
    if (arr[n] > max)                 // checking for max value
    {
        max = arr[n]; // changing max value
    }
    return max;
}

void main()
{
    int arr[] = {2, 4, 1222, 34, 1, 56, 0, 465, 4};
    int n = sizeof(arr) / sizeof(int);
    int max = max_number(arr, n - 1);               // calling function
    printf("Maximum number in array is:%d\n", max); // output
}