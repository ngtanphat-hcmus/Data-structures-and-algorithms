#include <stdio.h>

void interchange_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
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

int main(void)
{
    int a[] = {12, 2, 8, 5, 1, 6, 4, 15};
    int n = sizeof(a) / sizeof(a[0]); //Calculate the size of array
    printf("Before sorting: ");
    print_array(a, n);
    interchange_sort(a, n);
    printf("After sorting: ");
    print_array(a, n);
    return 0;
}
