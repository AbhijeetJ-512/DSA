#include <stdio.h>

int maxElement = -1;

void findMax(int arr[], int n, int currentIndex)
{
    if (currentIndex == n)
    {
        return;
    }

    if (arr[currentIndex] > maxElement)
    {
        maxElement = arr[currentIndex];
    }

    findMax(arr, n, currentIndex + 1);
}

int main()
{
    int arr[] = {5, 9, 2, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    findMax(arr, n, 0);

    printf("Maximum element: %d\n", maxElement);

    return 0;
}