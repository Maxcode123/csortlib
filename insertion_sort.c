#include <stdio.h>

#include "sorthelpers.h"

void insertion_sort(int *array, int length);

void main() 
{
    int array[] = {-1 -0, -500, 18, 5, -12, 12, 1, 1, 2, -1, 9, 78, 13, 5};
    int length = sizeof(array) / sizeof(int);

    printf("Unsorted array: ");
    sorthelpers_show(&array[0], length);
    printf("SORTING TRACE\n===========================================\n");

    insertion_sort(&array[0], length);

    if (sorthelpers_is_sorted(&array[0], length))
    {
        printf("===========================================\n");
        printf("Sorted array: ");
        sorthelpers_show(&array[0], length);
    }
}

void insertion_sort(int *array, int length)
{
    for (int i=1; i<length; i++)
    {
        printf("%d  ", i);
        sorthelpers_show(&array[0], length);
        for (int j=i; j>0 && sorthelpers_less(array[j], array[j-1]); j--)
        {
            sorthelpers_exchange(array, j, j-1);
        }
    }
}
