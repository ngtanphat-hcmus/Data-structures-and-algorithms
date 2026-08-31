#include <stdio.h>

void quick_sort(int a[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot = a[(left + right) / 2];

    while (i <= j)
    {
        while (a[i] < pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            i++;
            j--;
        }
    }

    if (left < j)
    {
        quick_sort(a, left, j);
    }

    if (i < right)
    {
        quick_sort(a, i, right);
    }
}

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

int main()
{
    int a[] = {12, 2, 8, 5, 1, 6, 4, 15};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting: ");
    print_array(a, n);

    quick_sort(a, 0, n - 1);

    printf("After sorting: ");
    print_array(a, n);

    return 0;
}
