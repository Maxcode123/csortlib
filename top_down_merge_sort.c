#include <stdio.h>

#include "sorthelpers.h"

void top_down_merge_sort(int *array, int length, int *aux, int lo, int hi);

void main() 
{
    int array[] = {102, -12, 0, 1, 2, 1234, -11, -43, -9, 0, 10, 17};
    int length = sizeof(array) / sizeof(int);
    int aux[length];

    printf("Unsorted array: ");
    sorthelpers_show(&array[0], length);
    top_down_merge_sort(&array[0], length, &aux[0], 0, length-1);

    if (sorthelpers_is_sorted(&array[0], length))
    {
        printf("===================================================\n");
        printf("Sorted array: ");
        sorthelpers_show(&array[0], length);
    }

}

void top_down_merge_sort(int *array, int length, int *aux, int lo, int hi)
{
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    top_down_merge_sort(&array[0], length, &aux[0], lo, mid);
    top_down_merge_sort(&array[0], length, &aux[0], mid+1, hi);
    sorthelpers_merge(&array[0], &aux[0], lo, mid, hi);
    
}
