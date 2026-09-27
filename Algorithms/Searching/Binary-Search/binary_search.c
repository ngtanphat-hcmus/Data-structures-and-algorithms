#include <stdio.h>

int binary_search(int a[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (a[mid] == target)
        {
            return mid;
        }

        if (a[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main(void)
{
    int a[] = {1, 2, 4, 5, 6, 8, 12, 15};
    int n = sizeof(a) / sizeof(a[0]);
    int target = 12;

    int result = binary_search(a, n, target);

    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}
