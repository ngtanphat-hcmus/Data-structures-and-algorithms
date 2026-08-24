# Interchange Sort

## Overview

Interchange Sort is one of the most basic and common comparison-based sorting algorithms.

The main idea of this method is to compare each element with the elements that come after it and swap them immediately when the condition is satisfied.

By changing the comparison condition, we can sort the array in ascending or descending order. For ascending order, we swap when the following element is smaller than the current element. For descending order, we swap when the following element is greater than the current element.

---

## Core Idea

As mentioned above, the main idea is to place the smallest element of the unsorted portion at the current position when we want to sort the array in ascending order.

To do that, we follow these steps for each position `i`:

1. Treat `a[i]` as the current element.
2. Compare `a[i]` with every element after it.
3. If a smaller element is found, swap it with `a[i]`.
4. Continue until the end of the array.
5. After the inner loop finishes, `a[i]` contains the smallest element in the unsorted portion.
6. Move to the next position and repeat.
7. The outer loop runs from `i = 0` to `i = n - 2`, while the inner loop runs from `j = i + 1` to `j = n - 1`.

For ascending order:

```c
if (a[j] < a[i])
{
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
```

For descending order, we can change the condition to:

```c
if (a[j] > a[i])
{
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
```

---

## How It Works

Consider the following array:

```text
12 2 8 5 1 6 4 15
```

We want to sort the array in ascending order.

### With `i = 0`

We start with `a[0] = 12`.

The inner loop runs from `j = 1` to `j = 7`. We compare `a[0]` with each element after it. If the condition `a[j] < a[i]` is satisfied, we swap the two elements immediately.

* Compare `12` with `2` → `2 < 12`, so swap:

```c
temp = a[0];
a[0] = a[1];
a[1] = temp;
```

Array:

```text
2 12 8 5 1 6 4 15
```

* Compare `a[0] = 2` with `8` → No swap.
* Compare `a[0] = 2` with `5` → No swap.
* Compare `a[0] = 2` with `1` → `1 < 2`, so swap:

```c
temp = a[0];
a[0] = a[4];
a[4] = temp;
```

Array:

```text
1 12 8 5 2 6 4 15
```

* Compare `a[0] = 1` with `6` → No swap.
* Compare `a[0] = 1` with `4` → No swap.
* Compare `a[0] = 1` with `15` → No swap.

Therefore, after `i = 0`:

```text
1 12 8 5 2 6 4 15
```

The first element is now in its correct position.

---

### With `i = 1`

Now, `a[1] = 12`.

The inner loop runs from `j = 2` to `j = 7`.

* Compare `12` with `8` → `8 < 12`, so swap:

```c
temp = a[1];
a[1] = a[2];
a[2] = temp;
```

Array:

```text
1 8 12 5 2 6 4 15
```

* Compare `a[1] = 8` with `5` → `5 < 8`, so swap:

```c
temp = a[1];
a[1] = a[3];
a[3] = temp;
```

Array:

```text
1 5 12 8 2 6 4 15
```

* Compare `a[1] = 5` with `2` → `2 < 5`, so swap:

```c
temp = a[1];
a[1] = a[4];
a[4] = temp;
```

Array:

```text
1 2 12 8 5 6 4 15
```

* Compare `a[1] = 2` with `6` → No swap.
* Compare `a[1] = 2` with `4` → No swap.
* Compare `a[1] = 2` with `15` → No swap.

Therefore, after `i = 1`:

```text
1 2 12 8 5 6 4 15
```

The first two elements are now in their correct positions.

---

### With `i = 2`

Now, `a[2] = 12`.

The inner loop runs from `j = 3` to `j = 7`.

* Compare `12` with `8` → `8 < 12`, so swap:

```c
temp = a[2];
a[2] = a[3];
a[3] = temp;
```

Array:

```text
1 2 8 12 5 6 4 15
```

* Compare `a[2] = 8` with `5` → `5 < 8`, so swap:

```c
temp = a[2];
a[2] = a[4];
a[4] = temp;
```

Array:

```text
1 2 5 12 8 6 4 15
```

* Compare `a[2] = 5` with `6` → No swap.
* Compare `a[2] = 5` with `4` → `4 < 5`, so swap:

```c
temp = a[2];
a[2] = a[6];
a[6] = temp;
```

Array:

```text
1 2 4 12 8 6 5 15
```

* Compare `a[2] = 4` with `15` → No swap.

Therefore, after `i = 2`:

```text
1 2 4 12 8 6 5 15
```

---

### With `i = 3`

Now, `a[3] = 12`.

The inner loop runs from `j = 4` to `j = 7`.

* Compare `12` with `8` → `8 < 12`, so swap:

```c
temp = a[3];
a[3] = a[4];
a[4] = temp;
```

Array:

```text
1 2 4 8 12 6 5 15
```

* Compare `a[3] = 8` with `6` → `6 < 8`, so swap:

```c
temp = a[3];
a[3] = a[5];
a[5] = temp;
```

Array:

```text
1 2 4 6 12 8 5 15
```

* Compare `a[3] = 6` with `5` → `5 < 6`, so swap:

```c
temp = a[3];
a[3] = a[6];
a[6] = temp;
```

Array:

```text
1 2 4 5 12 8 6 15
```

* Compare `a[3] = 5` with `15` → No swap.

Therefore, after `i = 3`:

```text
1 2 4 5 12 8 6 15
```

---

### With `i = 4`

Now, `a[4] = 12`.

The inner loop runs from `j = 5` to `j = 7`.

* Compare `12` with `8` → `8 < 12`, so swap:

```c
temp = a[4];
a[4] = a[5];
a[5] = temp;
```

Array:

```text
1 2 4 5 8 12 6 15
```

* Compare `a[4] = 8` with `6` → `6 < 8`, so swap:

```c
temp = a[4];
a[4] = a[6];
a[6] = temp;
```

Array:

```text
1 2 4 5 6 12 8 15
```

* Compare `a[4] = 6` with `15` → No swap.

Therefore, after `i = 4`:

```text
1 2 4 5 6 12 8 15
```

---

### With `i = 5`

Now, `a[5] = 12`.

The inner loop runs from `j = 6` to `j = 7`.

* Compare `12` with `8` → `8 < 12`, so swap:

```c
temp = a[5];
a[5] = a[6];
a[6] = temp;
```

Array:

```text
1 2 4 5 6 8 12 15
```

* Compare `a[5] = 8` with `15` → No swap.

Therefore, after `i = 5`:

```text
1 2 4 5 6 8 12 15
```

---

### With `i = 6`

Now, `a[6] = 12`.

The inner loop only has `j = 7`.

* Compare `12` with `15` → No swap.

Therefore, after `i = 6`:

```text
1 2 4 5 6 8 12 15
```

The array is now sorted in ascending order.

---

## Algorithm

The algorithm can be summarized as follows:

```text
for i = 0 to n - 2
    for j = i + 1 to n - 1
        if a[j] < a[i]
            swap a[i] and a[j]
```

For descending order, change the condition to:

```text
if a[j] > a[i]
    swap a[i] and a[j]
```

---

## Implementation in C

The C implementation will be added separately in:

`interchange_sort.c`

The implementation follows the algorithm described above and sorts the array in ascending order.

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

The algorithm always uses two nested loops to compare elements in the unsorted portion of the array.

The number of comparisons is approximately:

```text
(n - 1) + (n - 2) + ... + 1
```

which is:

```text
n(n - 1) / 2
```

Therefore, the time complexity is:

```text
O(n²)
```

### Space Complexity

```text
O(1)
```

Interchange Sort sorts the array in place and only requires a temporary variable for swapping elements.
