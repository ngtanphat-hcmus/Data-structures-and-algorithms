# QUICK SORT
## Overview

Unlike Basic Sorting algorithms, Divide and Conquer is another approach that can be used to improve the efficiency of sorting algorithms.

One of the most widely used algorithms based on this approach is Quick Sort. The main idea is to choose one element as a `pivot` and divide the array into two different parts:

- The left part contains elements smaller than the pivot.
- The right part contains elements greater than the pivot.

This process is called **partitioning**. After the partition is completed, the same process is recursively applied to the left and right parts of the array.

In this implementation, the middle element of each portion is chosen as the pivot.

## Core Idea

As mentioned above, the main idea of Quick Sort is to divide the array into smaller portions based on a `pivot`.

For each portion:

1. Choose the middle element as the pivot:

   ```c
   pivot = a[(left + right) / 2];
   ```

2. Set two pointers:

   - `i` starts from the left border.
   - `j` starts from the right border.

   The purpose of these two pointers is to find elements that are on the wrong side of the pivot.

   - The left pointer `i` moves to the right until it finds an element that should belong on the right side.
   - The right pointer `j` moves to the left until it finds an element that should belong on the left side.

   When both elements are found, they can be swapped.

3. Continue the partitioning process while `i <= j`.

   - Move `i` to the right while `a[i] < pivot`.

   ```c
   while (a[i] < pivot)
   {
       i++;
   }
   ```

   This means that elements smaller than the pivot are already on the correct side, so `i` keeps moving until it finds an element greater than or equal to the pivot.

   - Move `j` to the left while `a[j] > pivot`.

   ```c
   while (a[j] > pivot)
   {
       j--;
   }
   ```

   Similarly, elements greater than the pivot are already on the correct side, so `j` keeps moving until it finds an element smaller than or equal to the pivot.

   - After both pointers stop, check again whether `i <= j`.

   This condition must be checked again because `i` and `j` may have crossed while moving toward the center.

   If:

   ```text
   i > j
   ```

   the current partition is complete, so there is no valid pair of elements left to swap.

   - If `i <= j`, swap `a[i]` and `a[j]`.

   ```c
   temp = a[i];
   a[i] = a[j];
   a[j] = temp;
   ```

   Then move both pointers toward the center:

   ```c
   i++;
   j--;
   ```

   Repeat the process until `i > j`.

4. After the partitioning process is completed, recursively apply Quick Sort to the left and right portions of the array.

   ```c
   if (left < j)
   {
       quick_sort(a, left, j);
   }

   if (i < right)
   {
       quick_sort(a, i, right);
   }
   ```

The process continues until each portion contains zero or one element, which is already considered sorted.

## How It Works

Consider the following array:

```text
12 2 8 5 1 6 4 15
```

We want to sort the array in ascending order.

### First Partition

Set:

```text
left = 0
right = 7
```

The middle element is chosen as the pivot:

```text
pivot = a[(0 + 7) / 2]
      = a[3]
      = 5
```

Set two pointers:

```text
i = 0
j = 7
```

The left pointer `i` moves to the right until it finds an element greater than or equal to the pivot.

The right pointer `j` moves to the left until it finds an element smaller than or equal to the pivot.

At first:

```text
12 2 8 5 1 6 4 15
↑               ↑
i               j
```

`i` stops at `12` because `12 > 5`.

`j` moves left and stops at `4` because `4 < 5`.

Since `i <= j`, swap `12` and `4`:

```text
4 2 8 5 1 6 12 15
```

Then:

```text
i++
j--
```

Now `i` moves to the right and stops at `8`, while `j` moves to the left and stops at `1`.

Swap `8` and `1`:

```text
4 2 1 5 8 6 12 15
```

After that, the two pointers meet at the pivot and then cross:

```text
i > j
```

The first partition is complete.

The array is now divided into two smaller portions:

```text
4 2 1 | 5 | 8 6 12 15
```

Quick Sort is recursively applied to both sides.

### Left Portion

```text
4 2 1
```

Choose the middle element:

```text
pivot = 2
```

After partitioning:

```text
1 2 4
```

### Right Portion

```text
8 6 12 15
```

Choose the middle element:

```text
pivot = 6
```

After partitioning:

```text
6 8 12 15
```

The remaining smaller portions continue to be processed recursively.

Finally, the array becomes:

```text
1 2 4 5 6 8 12 15
```

The array is now sorted in ascending order.
## Algorithm

```text
quick_sort(a, left, right)

    i = left
    j = right

    pivot = a[(left + right) / 2]

    while i <= j

        while a[i] < pivot
            i = i + 1

        while a[j] > pivot
            j = j - 1

        if i <= j
            swap a[i] and a[j]

            i = i + 1
            j = j - 1

    if left < j
        quick_sort(a, left, j)

    if i < right
        quick_sort(a, i, right)
```

---

## Implementation in C

The C implementation will be added separately in:

`quick_sort.c`

A basic implementation can be written as:

```c
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

int main(void)
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
```

---

## Example

### Input

```text
12 2 8 5 1 6 4 15
```

### Output

```text
1 2 4 5 6 8 12 15
```

---

## Complexity Analysis

### Time Complexity

| Case | Time Complexity |
|---|---:|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n²) |

In the best and average cases, the pivot divides the array into relatively balanced portions.

At each level of recursion, the partitioning process examines approximately `n` elements, while the array is divided through approximately `log n` levels.

Therefore, the time complexity is:

```text
O(n log n)
```

In the worst case, the pivot repeatedly creates highly unbalanced portions. For example, one portion may contain almost all elements while the other contains very few elements.

In this case, the recursion depth can approach `n`, resulting in:

```text
O(n²)
```

### Space Complexity

In the average case, the recursion depth is approximately:

```text
O(log n)
```

Therefore, the average space complexity is:

```text
O(log n)
```

In the worst case, highly unbalanced partitions can cause the recursion depth to become:

```text
O(n)
```

---

## Note

In this implementation, the middle element **by index** is chosen as the pivot:

```c
pivot = a[(left + right) / 2];
```

This does not mean that the pivot is the median value of the portion. It only means that the element located at the middle position is selected.

Different implementations of Quick Sort may use different methods for choosing the pivot, such as the first element, the last element, or a random element.

