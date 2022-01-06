#include <stdio.h>
#include <stdlib.h>

#include "sorthelpers.h"


int sorthelpers_less(int first_value, int second_value)
{
    return first_value < second_value;
}

void sorthelpers_exchange(int *array, int first_index, int second_index)
{
    int temp = array[first_index];
    array[first_index] = array[second_index];
    array[second_index] = temp;
    return;
}

void sorthelpers_show(int *array, int length)
{
    for (int i=0; i<length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return;
}

int sorthelpers_is_sorted(int *array, int length)
{
    for (int i=1; i<length; i++)
    {
        if (sorthelpers_less(array[i], array[i-1]))
        {
            return 0;
        }
    }
    return 1;
}

void sorthelpers_merge(int *array, int *aux, int lo, int mid, int hi)
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
        else if (sorthelpers_less(aux[j], aux[i]))
        {
            array[k] = aux[j++];
        }
        else
        {
            array[k] = aux[i++];
        }
    }
}

int sorthelpers_min(int first_value, int second_value)
{
    return second_value ^ ((first_value ^ second_value) & -(first_value < second_value));
}

void sorthelpers_shuffle(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        int j = rand() % length;
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
    }
}