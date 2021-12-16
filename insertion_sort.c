#include <stdio.h>

int less(int first_value, int second_value);
void exchange(int *array, int first_index, int second_index);
void show(int *array, int length);
int is_sorted(int *array, int length);
void insertion_sort(int *array, int length);

void main() 
{
    int array[5] = {-1 -0, -500, 18, 5};
    int length = sizeof(array) / sizeof(int);

    printf("Unsorted array: ");
    show(&array[0], length);

    insertion_sort(&array[0], length);

    if (is_sorted(&array[0], length))
    {
        printf("Sorted array: ");
        show(&array[0], length);
    }
}

void insertion_sort(int *array, int length)
{
    for (int i=1; i<length; i++)
    {
        for (int j=i; j>0 && less(array[j], array[j-1]); j--)
        {
            exchange(array, j, j-1);
        }
    }
}

int less(int first_value, int second_value)
{
    return first_value < second_value;
}

void exchange(int *array, int first_index, int second_index)
{
    int temp = array[first_index];
    array[first_index] = array[second_index];
    array[second_index] = temp;
    return;
}

void show(int *array, int length)
{
    for (int i=0; i<length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return;
}

int is_sorted(int *array, int length)
{
    for (int i=1; i<length; i++)
    {
        if (less(array[i], array[i-1]))
        {
            return 0;
        }
    }
    return 1;
}