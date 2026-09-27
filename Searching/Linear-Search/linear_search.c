#include <stdio.h>

int linear_search(int a[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main(void)
{
    int a[] = {12, 2, 8, 5, 1, 6, 4, 15};
    int n = sizeof(a) / sizeof(a[0]);
    int target = 5;

    int result = linear_search(a, n, target);

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
