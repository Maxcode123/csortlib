#include <stdio.h>

int less(int first_value, int second_value);
void exchange(int *array, int first_index, int second_index);
void show(int *array, int length);
int is_sorted(int *array, int length);
void merge(int *array, int *aux, int lo, int mid, int hi);
void bottom_up_merge_sort(int *array, int length, int *aux);
int intmin(int first_value, int second_value);

void main()
{
    int array[] = {1032, -123, 2342, 0, 192, 3, -234, -29, 9, -10, -12, -3, 35};
    int length = sizeof(array) / sizeof(int);
    int aux[length];

    printf("Unsorted array: ");
    show(&array[0], length);
    bottom_up_merge_sort(&array[0], length, &aux[0]);

    if (is_sorted(&array[0], length))
    {
        printf("===================================================\n");
        printf("Sorted array: ");
        show(&array[0], length);
    }

}

void bottom_up_merge_sort(int *array, int length, int *aux)
{
    for (int len = 1; len < length; len *= 2)
    {
        for (int lo = 0; lo < length - len; lo += len+len)
        {
            merge(&array[0], &aux[0], lo, lo+len-1, intmin(lo+len+len-1, length-1));
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

void merge(int *array, int *aux, int lo, int mid, int hi)
{
    int i = lo;
    int j = mid + 1;
    for (int k = lo; k <= hi; k++)
    {
        aux[k] = array[k];
    }
    for (int k = lo; k <= hi; k++)
    {
        if (i > mid)
        {
            array[k] = aux[j++];
        }
        else if (j > hi)
        {
            array[k] = aux[i++];
        }
        else if (less(aux[j], aux[i]))
        {
            array[k] = aux[j++];
        }
        else
        {
            array[k] = aux[i++];
        }
    }
}

int intmin(int first_value, int second_value)
{
    return second_value ^ ((first_value ^ second_value) & -(first_value < second_value));
}