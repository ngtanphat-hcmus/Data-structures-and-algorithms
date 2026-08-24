# Insertion Sort

## Overview

Insertion Sort is a simple comparison-based sorting algorithm that builds the sorted portion of the array one element at a time.

The main idea is similar to the way we sort playing cards in our hand. We take one element from the unsorted portion and insert it into the correct position in the sorted portion.

For ascending order, larger elements in the sorted portion are shifted to the right until the correct position for the current element is found.

The algorithm starts from the second element (i = 1), since a single element by itself is already considered sorted.

---

## Core Idea

The main idea of Insertion Sort is to maintain a sorted portion on the left side of the array.

For each position `i`:

1. Treat `a[i]` as the current element, called the `key`.
2. Compare the `key` with the elements before it.
3. If an element is greater than the `key`, shift it one position to the right.
4. Continue moving backward through the sorted portion.
5. Stop when an element smaller than or equal to the `key` is found.
6. Insert the `key` into the correct position.
7. Move to the next element and repeat.

The outer loop runs from `i = 1` to `i = n - 1`.

For ascending order:

```c
while (j >= 0 && a[j] > key)
{
    a[j + 1] = a[j];
    j--;
}

a[j + 1] = key;
```

---

## How It Works

Consider the following array:

```text
12 2 8 5 1 6 4 15
```

We want to sort the array in ascending order.

The first element is considered already sorted:

```text
12 | 2 8 5 1 6 4 15
```

### With `i = 1`

The current key is:

```text
key = 2
```

Compare `2` with `12`.

Since `12 > 2`, shift `12` one position to the right.

```text
12 12 8 5 1 6 4 15
```

Insert `2` into the correct position:

```text
2 12 8 5 1 6 4 15
```

The sorted portion is now:

```text
2 12 | 8 5 1 6 4 15
```

---

### With `i = 2`

The current key is:

```text
key = 8
```

Compare `8` with `12`.

Since `12 > 8`, shift `12` to the right:

```text
2 12 12 5 1 6 4 15
```

Now compare `8` with `2`.

Since `2 < 8`, stop shifting and insert `8`:

```text
2 8 12 5 1 6 4 15
```

---

### With `i = 3`

The current key is:

```text
key = 5
```

`12 > 5` → shift `12`.

```text
2 8 12 12 1 6 4 15
```

`8 > 5` → shift `8`.

```text
2 8 8 12 1 6 4 15
```

`2 < 5` → stop shifting.

Insert `5`:

```text
2 5 8 12 1 6 4 15
```

---

### With `i = 4`

The current key is:

```text
key = 1
```

All elements before `1` are greater than it, so they are shifted one position to the right.

After inserting `1`:

```text
1 2 5 8 12 6 4 15
```

---

### With `i = 5`

The current key is:

```text
key = 6
```

`12 > 6` → shift.

`8 > 6` → shift.

`5 < 6` → stop.

After inserting `6`:

```text
1 2 5 6 8 12 4 15
```

---

### With `i = 6`

The current key is:

```text
key = 4
```

Shift all elements greater than `4` to the right.

After inserting `4`:

```text
1 2 4 5 6 8 12 15
```

---

### With `i = 7`

The current key is:

```text
key = 15
```

Since `15` is already greater than all the elements before it, no shifting is required.

The array remains:

```text
1 2 4 5 6 8 12 15
```

The array is now sorted in ascending order.

---

## Algorithm

```text
for i = 1 to n - 1
    key = a[i]
    j = i - 1

    while j >= 0 and a[j] > key
        a[j + 1] = a[j]
        j = j - 1

    a[j + 1] = key
```

---

## Implementation in C

The C implementation will be added separately in:

`insertion_sort.c`

A basic implementation can be written as:

```c
#include <stdio.h>

void insertion_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
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

    insertion_sort(a, n);

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
| Best    |            O(n) |
| Average |           O(n²) |
| Worst   |           O(n²) |

In the best case, the array is already sorted. Each element only needs to be compared with the previous element, so the time complexity is:

```text
O(n)
```

In the average and worst cases, an element may need to be compared with and shifted past many previous elements.

Therefore, the average-case and worst-case time complexities are:

```text
O(n²)
```

### Space Complexity

```text
O(1)
```

Insertion Sort sorts the array in place and only requires a small constant amount of additional memory for variables such as `key` and `j`.
