#include <stdio.h>

#include "sorthelpers.h"

void quicksort(int *array, int lo, int hi);

void main()
{
    int array[] = {12, 102, -12, 23, 0, 1, -3, 28, -94, 183, 401, 4029, 138, -2};
    int length = sizeof(array) / sizeof(int);

    printf("Unsorted array: ");
    sorthelpers_show(&array[0], length);
    sorthelpers_shuffle(&array[0], length);
    quicksort(&array[0], 0, length-1);

    if (sorthelpers_is_sorted(&array[0], length))
    {
        printf("===================================================\n");
        printf("Sorted array: ");
        sorthelpers_show(&array[0], length);
    }
}

void quicksort(int *array, int lo, int hi)
{
    if (hi <= lo) return;
    int j = sorthelpers_partition(&array[0], lo, hi);
    quicksort(&array[0], lo, j-1);
    quicksort(&array[0], j+1, hi);
}