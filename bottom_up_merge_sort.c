#include <stdio.h>

#include "sorthelpers.h"

void bottom_up_merge_sort(int *array, int length, int *aux);

void main()
{
    int array[] = {1032, -123, 2342, 0, 192, 3, -234, -29, 9, -10, -12, -3, 35};
    int length = sizeof(array) / sizeof(int);
    int aux[length];

    printf("Unsorted array: ");
    sorthelpers_show(&array[0], length);
    bottom_up_merge_sort(&array[0], length, &aux[0]);

    if (sorthelpers_is_sorted(&array[0], length))
    {
        printf("===================================================\n");
        printf("Sorted array: ");
        sorthelpers_show(&array[0], length);
    }

}

void bottom_up_merge_sort(int *array, int length, int *aux)
{
    for (int len = 1; len < length; len *= 2)
    {
        for (int lo = 0; lo < length - len; lo += len+len)
        {
            sorthelpers_merge(&array[0], &aux[0], lo, lo+len-1, sorthelpers_min(lo+len+len-1, length-1));
        }
    }
}
