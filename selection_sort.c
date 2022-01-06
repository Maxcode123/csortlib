#include <stdio.h>

#include "sorthelpers.h"

void selection_sort(int *array, int length);

void main() 
{
    int array[] = {-1 -100, 2, 103, 5, -101, -102, 55, 19, 2, 1, 0, 5, 11, 9};
    int length = sizeof(array) / sizeof(int);

    printf("Unsorted array: ");
    sorthelpers_show(&array[0], length);
    printf("SORTING TRACE\n==============================================\n");

    selection_sort(&array[0], length);

    if (sorthelpers_is_sorted(&array[0], length))
    {
        printf("==============================================\n");
        printf("Sorted array: ");
        sorthelpers_show(&array[0], length);
    }
}

void selection_sort(int *array, int length)
{
    for (int i=0; i<length; i++)
    {
        printf("%d  ", i);
        sorthelpers_show(&array[0], length);
        
        int min = i;
        for (int j=i+1; j<length; j++)
        {
            if (sorthelpers_less(array[j], array[min]))
            {
                min = j;
            }
        }
        sorthelpers_exchange(&array[0], i, min);
    }
}
