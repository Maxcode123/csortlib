#include <stdio.h>

int less(int first_value, int second_value);
void exchange(int *array, int first_index, int second_index);
void show(int *array, int length);
int is_sorted(int *array, int length);
void merge(int *array, int *aux, int lo, int mid, int hi);
void top_down_merge_sort(int *array, int length, int *aux, int lo, int hi);

void main() 
{
    int array[] = {102, -12, 0, 1, 2, 1234, -11, -43, -9, 0, 10, 17};
    int length = sizeof(array) / sizeof(int);
    int aux[length];

    printf("Unsorted array: ");
    show(&array[0], length);
    top_down_merge_sort(&array[0], length, &aux[0], 0, length-1);

    if (is_sorted(&array[0], length))
    {
        printf("===================================================\n");
        printf("Sorted array: ");
        show(&array[0], length);
    }

}

void top_down_merge_sort(int *array, int length, int *aux, int lo, int hi)
{
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    top_down_merge_sort(&array[0], length, &aux[0], lo, mid);
    top_down_merge_sort(&array[0], length, &aux[0], mid+1, hi);
    merge(&array[0], &aux[0], lo, mid, hi);
    
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