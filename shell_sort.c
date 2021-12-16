#include <stdio.h>

int less(int first_value, int second_value);
void exchange(int *array, int first_index, int second_index);
void show(int *array, int length);
int is_sorted(int *array, int length);
void shell_sort(int *array, int length);

void main() 
{
    int array[6] = {-1 -2129, 1238, 0, 0, 1};
    int length = sizeof(array) / sizeof(int);

    printf("Unsorted array: ");
    show(&array[0], length);

    shell_sort(&array[0], length);

    if (is_sorted(&array[0], length))
    {
        printf("Sorted array: ");
        show(&array[0], length);
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
            for (int j=i; j>=h && less(array[j], array[j-h]); j-=h)
            {
                exchange(array, j, j-h);
            }
        }
        h = h/3;
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