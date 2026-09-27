# Linear Search

## Overview

Linear Search is one of the simplest searching algorithms. It searches for a target value by checking each element of the array sequentially from the beginning until the target is found or the end of the array is reached.

This algorithm does not require the array to be sorted, making it simple and useful for small or unsorted datasets.

An optimized variation called **Sentinel Linear Search** can also be used. It temporarily places the target value at the end of the array as a sentinel, removing the need to check the array boundary during every iteration. However, its overall time complexity is still `O(n)`.

---

## Algorithm

For a target value `target`:

```text
for i = 0 to n - 1

    if a[i] == target
        return i

return -1
```

The algorithm checks each element one by one.

If the target is found, its index is returned.

If the algorithm reaches the end of the array without finding the target, it returns:

```text
-1
```

---

## How It Works

Consider the following array:

```text
12 2 8 5 1 6 4 15
```

Suppose we want to find:

```text
target = 5
```

Start from the first element and compare each element with the target.

```text
12 == 5 → No

2 == 5 → No

8 == 5 → No

5 == 5 → Found
```

The target is found at:

```text
index = 3
```

Therefore:

```text
12 2 8 5 1 6 4 15
        ↑
      target
```

Once the target is found, the searching process stops immediately.

If the target does not exist in the array, the algorithm continues until the last element and returns:

```text
-1
```

---

## Implementation in C

The C implementation will be added separately in:

`linear_search.c`

A basic implementation can be written as:

```c
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
```

---

## Example

### Input

```text
Array:  12 2 8 5 1 6 4 15
Target: 5
```

### Output

```text
Element found at index 3
```

---

## Complexity Analysis

### Time Complexity

| Case | Time Complexity |
|---|---:|
| Best | O(1) |
| Average | O(n) |
| Worst | O(n) |

In the best case, the target is the first element of the array, so only one comparison is required.

```text
O(1)
```

In the average case, several elements may need to be checked before finding the target.

In the worst case, the target is either the last element or does not exist in the array, so all `n` elements must be checked.

```text
O(n)
```

### Space Complexity

```text
O(1)
```

Linear Search only uses a constant amount of additional memory and does not require any extra arrays.
