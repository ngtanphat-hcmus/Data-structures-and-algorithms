# Bubble Sort

## Overview

Bubble Sort is a simple comparison-based sorting algorithm. It repeatedly compares two adjacent elements and swaps them if they are in the wrong order.

For ascending order, if the left element is greater than the right element, they are swapped. After each pass, the largest element in the unsorted portion gradually moves toward the end of the array.

The algorithm gets its name from this behavior: larger elements move toward the end of the array through repeated adjacent swaps, similar to bubbles rising to the surface.

---

## Core Idea

The main idea of Bubble Sort is to repeatedly compare adjacent elements and move the largest element of the unsorted portion to the end.

For each pass:

1. Start from the beginning of the array.
2. Compare `a[j]` with the adjacent element `a[j + 1]`.
3. If `a[j] > a[j + 1]`, swap them.
4. Continue comparing adjacent elements until reaching the end of the unsorted portion.
5. After one complete pass, the largest element in the unsorted portion reaches its correct position at the end.
6. Reduce the unsorted portion and repeat the process.
7. The outer loop runs from `i = 0` to `i = n - 2`, while the inner loop runs from `j = 0` to `j = n - i - 2`.

For ascending order:

```c
if (a[j] > a[j + 1])
{
    temp = a[j];
    a[j] = a[j + 1];
    a[j + 1] = temp;
}
```

For descending order, we can change the condition to:

```c
if (a[j] < a[j + 1])
{
    temp = a[j];
    a[j] = a[j + 1];
    a[j + 1] = temp;
}
```

---

## How It Works

Consider the following array:

```text
12 2 8 5 1 6 4 15
```

We want to sort the array in ascending order.

### Pass 1 — `i = 0`

Compare adjacent elements from left to right.

* `12 > 2` → swap

```text
2 12 8 5 1 6 4 15
```

* `12 > 8` → swap

```text
2 8 12 5 1 6 4 15
```

* `12 > 5` → swap

```text
2 8 5 12 1 6 4 15
```

* `12 > 1` → swap

```text
2 8 5 1 12 6 4 15
```

* `12 > 6` → swap

```text
2 8 5 1 6 12 4 15
```

* `12 > 4` → swap

```text
2 8 5 1 6 4 12 15
```

* `12 > 15` → No swap, array remains unchanged.

After Pass 1:

```text
2 8 5 1 6 4 12 15
```

The largest element of the unsorted portion has moved toward the end of the array.

---

### Pass 2 — `i = 1`

Start with:

```text
2 8 5 1 6 4 12 | 15
```

* `2 > 8` → No swap, array remains unchanged.
* `8 > 5` → swap

```text
2 5 8 1 6 4 12 15
```

* `8 > 1` → swap

```text
2 5 1 8 6 4 12 15
```

* `8 > 6` → swap

```text
2 5 1 6 8 4 12 15
```

* `8 > 4` → swap

```text
2 5 1 6 4 8 12 15
```

* `8 > 12` → No swap, array remains unchanged.

After Pass 2:

```text
2 5 1 6 4 8 12 15
```

---

### Pass 3 — `i = 2`

* `2 > 5` → No swap, array remains unchanged.
* `5 > 1` → swap

```text
2 1 5 6 4 8 12 15
```

* `5 > 6` → No swap, array remains unchanged.
* `6 > 4` → swap

```text
2 1 5 4 6 8 12 15
```

* `6 > 8` → No swap, array remains unchanged.

After Pass 3:

```text
2 1 5 4 6 8 12 15
```

---

### Pass 4 — `i = 3`

* `2 > 1` → swap

```text
1 2 5 4 6 8 12 15
```

* `2 > 5` → No swap, array remains unchanged.
* `5 > 4` → swap

```text
1 2 4 5 6 8 12 15
```

* `5 > 6` → No swap, array remains unchanged.

After Pass 4:

```text
1 2 4 5 6 8 12 15
```

The array is already sorted after Pass 4. However, the basic version of Bubble Sort continues the remaining passes because it does not check whether any swaps occurred.


## Algorithm

```text
for i = 0 to n - 2
    for j = 0 to n - i - 2
        if a[j] > a[j + 1]
            swap a[j] and a[j + 1]
```

We can also add a flag to check whether any swaps occur during a pass. If no swaps are made, the array is already sorted, so the algorithm can stop early. This optimization improves the best-case time complexity from O(n²) to O(n).

---

## Implementation in C

The C implementation will be added separately in:

`bubble_sort.c`

A basic implementation can be written as:

```c
#include <stdio.h>

void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
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

    bubble_sort(a, n);

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

| Case    | Time Complexity |
| ------- | --------------: |
| Best    |           O(n²) |
| Average |           O(n²) |
| Worst   |           O(n²) |

For the basic implementation above, Bubble Sort always executes the nested loops even if the array is already sorted. Therefore, its best-case time complexity is also `O(n²)`.

If we add an optimization to detect whether any swap occurred during a pass, the best-case complexity can be improved to:

```text
O(n)
```

The average and worst cases remain:

```text
O(n²)
```

### Space Complexity

```text
O(1)
```

Bubble Sort sorts the array in place and only requires a temporary variable for swapping adjacent elements.
