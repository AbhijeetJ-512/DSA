#include <stdio.h>
void binary_search(int a[], int start, int end, int search)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == search)
        {
            printf("%d ", a[mid]);
            return;
        }
        else if (a[mid] > search)
        {
            binary_search(a, start, mid - 1, search);
        }
        else if (a[mid] < search)
        {
            binary_search(a, mid + 1, end, search);
        }
    }
}

void main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int search = 1;
    binary_search(a, 0, 4, search);
}