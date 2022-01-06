#include <stdio.h>

#include "sorthelpers.h"

void shell_sort(int *array, int length);

void main() 
{
    int array[] = {-1 -2129, 1238, 0, 0, 1, 9, 8, -15, -28, -27, 101, -2};
    int length = sizeof(array) / sizeof(int);

    printf("Unsorted array: ");
    sorthelpers_show(&array[0], length);
    printf("SORTING TRACE\n===================================================\n");

    shell_sort(&array[0], length);

    if (sorthelpers_is_sorted(&array[0], length))
    {
        printf("===================================================\n");
        printf("Sorted array: ");
        sorthelpers_show(&array[0], length);
    }
}

void shell_sort(int *array, int length)
{
    int h = 1;
    while (h<length/3)
    {
        h = 3*h + 1;
    }
    while (h>=1)
    {
        for (int i=h; i<length; i++)
        {
            printf("%d  ", i);
            sorthelpers_show(&array[0], length);
            
            for (int j=i; j>=h && sorthelpers_less(array[j], array[j-h]); j-=h)
            {
                sorthelpers_exchange(array, j, j-h);
            }
        }
        h = h/3;
    }
}
