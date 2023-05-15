#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void binary_search(int arr[], int l, int h, int k)
{
    if (l == h)
    {
        printf("Unsuccesfull");
    }
    int mid = (h + l) / 2;
    if (arr[mid] == k)
    {
        printf("Successfull");
        exit(0);
    }
    if (arr[mid] > k)
    {
        h = mid - 1;
    }
    else
    {
        l = mid + 1;
    }
    binary_search(arr, l, h, k);
}

void main()
{
    int arr[] = {2, 1222, 34, 1, 56, 0, 465, 4};
    int n = sizeof(arr) / sizeof(int);
    sort(arr, n);
    printf("Enter the element u wanrt to search:\n");
    int k;
    scanf("%d", &k);
    binary_search(arr, 0, n - 1, k);
}