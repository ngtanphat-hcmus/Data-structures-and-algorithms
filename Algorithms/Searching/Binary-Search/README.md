# Binary Search

## Overview

Binary Search is an efficient searching algorithm that works on a **sorted array**.

Instead of checking each element one by one, Binary Search repeatedly compares the target with the middle element and eliminates half of the remaining search space.

Because the search space is divided in half after each comparison, Binary Search is much more efficient than Linear Search for large sorted arrays.

---

## Algorithm

For a sorted array and a target value:

```text
left = 0
right = n - 1

while left <= right

    mid = left + (right - left) / 2

    if a[mid] == target
        return mid

    if a[mid] < target
        left = mid + 1

    else
        right = mid - 1

return -1
```

The algorithm compares the target with the middle element.

- If the middle element is equal to the target, return its index.
- If the middle element is smaller than the target, search the right half.
- If the middle element is greater than the target, search the left half.
- If `left > right`, the target does not exist in the array.

---

## How It Works

Consider the following sorted array:

```text
1 2 4 5 6 8 12 15
```

Suppose we want to find:

```text
target = 12
```

### Step 1

Set the boundaries:

```text
left = 0
right = 7
```

Calculate the middle:

```text
mid = left + (right - left) / 2
    = 0 + (7 - 0) / 2
    = 3
```

The middle element is:

```text
a[3] = 5
```

Compare:

```text
5 < 12
```

Since the target is greater than the middle element, the target can only be in the right half.

Therefore:

```text
left = mid + 1
     = 4
```

The remaining search space is:

```text
1 2 4 5 | 6 8 12 15
          ↑         ↑
        left      right
```

---

### Step 2

Calculate the new middle:

```text
mid = 4 + (7 - 4) / 2
    = 5
```

The middle element is:

```text
a[5] = 8
```

Compare:

```text
8 < 12
```

Again, the target must be in the right half.

Therefore:

```text
left = mid + 1
     = 6
```

The remaining search space is:

```text
6 8 | 12 15
       ↑    ↑
     left  right
```

---

### Step 3

Calculate the new middle:

```text
mid = 6 + (7 - 6) / 2
    = 6
```

The middle element is:

```text
a[6] = 12
```

Compare:

```text
12 == 12
```

The target is found at:

```text
index = 6
```

The search stops.

---

## Implementation in C

The C implementation will be added separately in:

`binary_search.c`

A basic implementation can be written as:

```c
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
```

---

## Example

### Input

```text
Array:  1 2 4 5 6 8 12 15
Target: 12
```

### Output

```text
Element found at index 6
```

---

## Complexity Analysis

### Time Complexity

| Case | Time Complexity |
|---|---:|
| Best | O(1) |
| Average | O(log n) |
| Worst | O(log n) |

In the best case, the target is the middle element of the array, so only one comparison is required.

In the average and worst cases, the search space is divided by approximately two after each comparison.

Therefore, the time complexity is:

```text
O(log n)
```

### Space Complexity

```text
O(1)
```

This implementation uses an iterative approach and only requires a constant amount of additional memory.

---

## Note

Binary Search requires the array to be **sorted** before searching.

Unlike Linear Search, which can work directly on an unsorted array, Binary Search relies on the order of the elements to eliminate half of the search space after each comparison.
