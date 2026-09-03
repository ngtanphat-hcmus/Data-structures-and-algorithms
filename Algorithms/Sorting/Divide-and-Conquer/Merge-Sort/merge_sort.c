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
