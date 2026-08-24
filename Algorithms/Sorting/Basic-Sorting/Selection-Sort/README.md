# Selection Sort

## Overview

Selection Sort is a simple comparison-based sorting algorithm. The main idea of this method is to repeatedly find the smallest element from the unsorted portion of the array and place it at the beginning of that portion.

Unlike Interchange Sort, Selection Sort does not swap immediately when it finds a smaller element. Instead, it keeps track of the position of the smallest element and performs the swap after finishing the search.

---

## Core Idea

For ascending order, the main idea is to find the smallest element in the unsorted portion and put it at the current position.

For each position `i`:

1. Assume `a[i]` is the smallest element.
2. Store its position in `min_index`.
3. Compare `a[i]` with every element after it.
4. If a smaller element is found, update `min_index`.
5. Continue until the end of the unsorted portion.
6. Swap `a[i]` with `a[min_index]`.
7. Move to the next position and repeat.

The outer loop runs from `i = 0` to `i = n - 2`, while the inner loop runs from `j = i + 1` to `j = n - 1`.

For ascending order:

```c
if (a[j] < a[min_index])
{
    min_index = j;
}
```

After finding the minimum:

```c
temp = a[i];
a[i] = a[min_index];
a[min_index] = temp;
```

---

## How It Works

Consider the following array:

```text
12 2 8 5 1 6 4 15
```

We want to sort the array in ascending order.

### With `i = 0`

Start with:

```text
12 2 8 5 1 6 4 15
↑
i
```

Assume `a[0] = 12` is the minimum.

```text
min_index = 0
```

Now compare `12` with the elements from `j = 1` to `j = 7`.

* `2 < 12` → update `min_index = 1`
* `8 < 2` → No
* `5 < 2` → No
* `1 < 2` → update `min_index = 4`
* `6 < 1` → No
* `4 < 1` → No
* `15 < 1` → No

The minimum element is `1`, located at index `4`.

Now swap `a[0]` and `a[4]`:

```c
temp = a[0];
a[0] = a[4];
a[4] = temp;
```

Array:

```text
1 2 8 5 12 6 4 15
```

The first element is now in its correct position.

### With `i = 1`

The unsorted portion is:

```text
1 | 2 8 5 12 6 4 15
    ↑
    i
```

Assume `a[1] = 2` is the minimum.

Compare it with the remaining elements.

No element is smaller than `2`, so `min_index` remains `1`.

No effective swap is needed.

Array remains:

```text
1 2 8 5 12 6 4 15
```

### With `i = 2`

Assume `a[2] = 8` is the minimum.

Compare it with the elements after it:

* `5 < 8` → `min_index = 3`
* `12 < 5` → No
* `6 < 5` → No
* `4 < 5` → `min_index = 6`
* `15 < 4` → No

The minimum is `4` at index `6`.

Swap:

```c
temp = a[2];
a[2] = a[6];
a[6] = temp;
```

Array:

```text
1 2 4 5 12 6 8 15
```

### With `i = 3`

The unsorted portion is:

```text
1 2 4 | 5 12 6 8 15
        ↑
        i
```

`5` is already the smallest element in this portion.

No effective swap is needed.

Array:

```text
1 2 4 5 12 6 8 15
```

### With `i = 4`

Assume `12` is the minimum.

* `6 < 12` → `min_index = 5`
* `8 < 6` → No
* `15 < 6` → No

The minimum is `6`.

Swap:

```c
temp = a[4];
a[4] = a[5];
a[5] = temp;
```

Array:

```text
1 2 4 5 6 12 8 15
```

### With `i = 5`

Assume `12` is the minimum.

* `8 < 12` → `min_index = 6`
* `15 < 8` → No

Swap:

```c
temp = a[5];
a[5] = a[6];
a[6] = temp;
```

Array:

```text
1 2 4 5 6 8 12 15
```

### With `i = 6`

Compare `12` with `15`.

No smaller element is found.

The array is now sorted:

```text
1 2 4 5 6 8 12 15
```

---

## Algorithm

```text
for i = 0 to n - 2
    min_index = i

    for j = i + 1 to n - 1
        if a[j] < a[min_index]
            min_index = j

    swap a[i] and a[min_index]
```

---

## Implementation in C

The C implementation will be added separately in:

`selection_sort.c`

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

Selection Sort always searches through the remaining unsorted portion to find the minimum element, even when the array is already sorted.

The number of comparisons is approximately:

```text
(n - 1) + (n - 2) + ... + 1
```

Therefore, the time complexity is:

```text
O(n²)
```

### Space Complexity

```text
O(1)
```

Selection Sort sorts the array in place and only uses a constant amount of additional memory.
