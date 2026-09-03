# Merge Sort

## Overview

Merge Sort is an efficient sorting algorithm based on the **Divide and Conquer** approach.

In this implementation, Merge Sort is performed using a **bottom-up approach** instead of recursion.

The main idea is to distribute groups of elements from the original array alternately into two temporary arrays, `B` and `C`. The corresponding groups from these two arrays are then compared and merged back into the original array in sorted order.

At the beginning, each group contains only one element. After each complete merging round, the number of elements in each group is doubled:

```text
1 → 2 → 4 → 8 → ...
```

The process continues until the entire array becomes one sorted group.

---

## Core Idea

The main idea of this version of Merge Sort consists of two main processes: **distribution** and **merging**.

1. Start with a group size of:

   ```c
   run_size = 1;
   ```

   A single element is already considered sorted.

2. Take groups of `run_size` elements from the original array and distribute them alternately into two temporary arrays, `B` and `C`.

   For example, when:

   ```text
   run_size = 1
   ```

   elements are distributed one by one:

   ```text
   Original: 12 2 8 5 1 6 4 15

   B: 12 8 1 4
   C: 2  5 6 15
   ```

3. Take one group from `B` and one corresponding group from `C`.

4. Compare the first remaining elements of the two groups.

   - If the element from `B` is smaller, copy it back into the original array.
   - Otherwise, copy the element from `C`.

5. Continue comparing until one of the two groups has no elements left.

6. Copy the remaining elements from the other group into the original array.

7. After all groups have been merged back, double the group size:

   ```c
   run_size *= 2;
   ```

8. Repeat the distribution and merging processes until:

   ```text
   run_size >= n
   ```

After every round, the size of each sorted group becomes larger until the entire array is sorted.

---

## How It Works

Consider the following array:

```text
12 2 8 5 1 6 4 15
```

We want to sort the array in ascending order.

At the beginning:

```text
run_size = 1
```

This means that we take one element at a time from the original array and distribute the elements alternately into two temporary arrays, `B` and `C`.

---

### Round 1 — `run_size = 1`

Original array:

```text
12 2 8 5 1 6 4 15
```

Take one element at a time and distribute them alternately:

```text
Take 12 → B
Take 2  → C
Take 8  → B
Take 5  → C
Take 1  → B
Take 6  → C
Take 4  → B
Take 15 → C
```

Therefore:

```text
B: 12 8 1 4
C: 2  5 6 15
```

Now compare the corresponding groups from `B` and `C`.

Since `run_size = 1`, each group contains only one element.

Compare:

```text
B: 12
C: 2
```

Since `2 < 12`, place `2` into the original array first, then place the remaining `12`.

```text
A: 2 12
```

Next:

```text
B: 8
C: 5
```

Since `5 < 8`:

```text
A: 2 12 5 8
```

Next:

```text
B: 1
C: 6
```

Since `1 < 6`:

```text
A: 2 12 5 8 1 6
```

Finally:

```text
B: 4
C: 15
```

Since `4 < 15`:

```text
A: 2 12 5 8 1 6 4 15
```

After the first round, each sorted group contains two elements:

```text
[2 12] [5 8] [1 6] [4 15]
```

Now double the group size:

```text
run_size = 2
```

---

### Round 2 — `run_size = 2`

Now take two elements at a time from the original array and distribute the groups alternately into `B` and `C`.

```text
Take [2 12] → B
Take [5 8]  → C
Take [1 6]  → B
Take [4 15] → C
```

Therefore:

```text
B: [2 12] [1 6]
C: [5 8]  [4 15]
```

Now compare the first group from `B` with the first group from `C`.

```text
B group: 2 12
C group: 5 8
```

Compare the first remaining elements:

```text
2 < 5
```

Take `2` from `B` and place it into the original array.

```text
A: 2
```

Now compare:

```text
12 and 5
```

Since `5 < 12`, take `5` from `C`.

```text
A: 2 5
```

Compare:

```text
12 and 8
```

Since `8 < 12`, take `8` from `C`.

```text
A: 2 5 8
```

The current group in `C` is now empty, so copy the remaining element from `B`:

```text
A: 2 5 8 12
```

Continue with the next pair of groups:

```text
B group: 1 6
C group: 4 15
```

Compare `1` and `4`:

```text
1 < 4
```

Take `1`.

Then compare `6` and `4`:

```text
4 < 6
```

Take `4`.

Then compare `6` and `15`:

```text
6 < 15
```

Take `6`.

Finally, copy the remaining `15`.

The original array becomes:

```text
2 5 8 12 1 4 6 15
```

Now each sorted group contains four elements:

```text
[2 5 8 12] [1 4 6 15]
```

Double the group size again:

```text
run_size = 4
```

---

### Round 3 — `run_size = 4`

Take four elements at a time:

```text
Take [2 5 8 12] → B
Take [1 4 6 15] → C
```

Therefore:

```text
B: 2 5 8 12
C: 1 4 6 15
```

Now compare the first remaining elements of `B` and `C`:

```text
2 and 1 → take 1
2 and 4 → take 2
5 and 4 → take 4
5 and 6 → take 5
8 and 6 → take 6
8 and 15 → take 8
12 and 15 → take 12
```

`B` is now empty, so copy the remaining element from `C`:

```text
15
```

The original array becomes:

```text
1 2 4 5 6 8 12 15
```

The entire array is now sorted.

Since:

```text
run_size = 8
```

and the array contains only `8` elements, the algorithm stops.

## Algorithm

```text
run_size = 1

while run_size < n

    distribute groups of run_size elements
    alternately from the original array into B and C

    take one group from B
    take one corresponding group from C

    while both groups still contain elements

        compare the first remaining elements

        copy the smaller element
        back into the original array

    copy the remaining elements from B, if any

    copy the remaining elements from C, if any

    continue with the next pair of groups

    run_size = run_size * 2
```

The group size therefore increases as:

```text
1 → 2 → 4 → 8 → ...
```

until the entire array is sorted.

---

## Implementation in C

The C implementation will be added separately in:

`merge_sort.c`

A basic implementation using two temporary arrays can be written as:

```c
#include <stdio.h>

void merge_sort(int a[], int n)
{
    int B[n];
    int C[n];

    int run_size = 1;

    while (run_size < n)
    {
        int b_count = 0;
        int c_count = 0;
        int pos = 0;
        int to_B = 1;

        // Distribute groups alternately into B and C
        while (pos < n)
        {
            int count = 0;

            while (count < run_size && pos < n)
            {
                if (to_B)
                {
                    B[b_count++] = a[pos++];
                }
                else
                {
                    C[c_count++] = a[pos++];
                }

                count++;
            }

            to_B = !to_B;
        }

        int i = 0;
        int j = 0;
        int k = 0;

        // Merge corresponding groups from B and C
        while (i < b_count || j < c_count)
        {
            int end_B = i + run_size;
            int end_C = j + run_size;

            if (end_B > b_count)
            {
                end_B = b_count;
            }

            if (end_C > c_count)
            {
                end_C = c_count;
            }

            while (i < end_B && j < end_C)
            {
                if (B[i] <= C[j])
                {
                    a[k++] = B[i++];
                }
                else
                {
                    a[k++] = C[j++];
                }
            }

            while (i < end_B)
            {
                a[k++] = B[i++];
            }

            while (j < end_C)
            {
                a[k++] = C[j++];
            }
        }

        run_size *= 2;
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

    merge_sort(a, n);

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
| Worst | O(n log n) |

After each round, the size of each sorted group is doubled:

```text
1 → 2 → 4 → 8 → ...
```

Therefore, approximately:

```text
log n
```

rounds are required.

During each round, approximately `n` elements are distributed and merged.

Therefore, the overall time complexity is:

```text
O(n log n)
```

Merge Sort maintains the same time complexity in the best, average, and worst cases.

### Space Complexity

```text
O(n)
```

This implementation requires additional memory because two temporary arrays, `B` and `C`, are used during the distribution and merging processes.

---

## Note

This implementation uses an **iterative bottom-up Merge Sort**.

Instead of recursively dividing the array into smaller portions, it begins with sorted groups of one element and repeatedly merges them into larger sorted groups.

The group size doubles after each round:

```text
1 → 2 → 4 → 8 → ...
```

This is different from the recursive implementation of Merge Sort, but both approaches follow the same main idea of combining smaller sorted portions into larger sorted portions.
