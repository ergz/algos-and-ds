#include <stdio.h>


int brute_force_inv_counter(int a[], int len)
{
    int total_inversions = 0;

    for (int i = 0; i < len; i++) // base iter
    {
        for (int j = i; j < len; j++)
        {
            if (a[i] > a[j])
            {
                total_inversions++;
            }
        }
    }

    return total_inversions;
}

/**
 * Merge arrays and count inversions
 * \param *out[] pointer to array where the sorted, merge array is to be written to
 * \param a[] array of integers for left
 * \param b[] array of integers for right
 * \param out_len the output length, should be the sum of len(a) + len(b)
 * \return total number of inversions

*/
int merge_and_count_inversions(int out[], int a[], int b[], int out_len)
{
    int i = 0;
    int j = 0;
    int split_counts = 0;

    for (int k = 0; k < out_len; k++)
    {
        if (a[i] < b[j])
        {
            out[k] = a[i];
            i++;
        }
        else 
        {
            out[k] = b[j];
            j++;
            // this case only happens when there is a split inversion
            split_counts += split_counts + ((out_len / 2) - i);
        }
    }

    return(split_counts);
}



int main(void)
{

    int arr[] = {1, 2, 3, 9, 12, 8, 7};
    int out[12];
    int a[6] = {1, 2, 3, 6, 7, 8};
    int b[6] = {5, 9, 10, 11, 12, 13};

    int result = brute_force_inv_counter(arr, 7);

    int total_inversion_splits = merge_and_count_inversions(out, a, b, 12);



    printf("the total inversion splits are: %d\n", total_inversion_splits);

    return(0);
}