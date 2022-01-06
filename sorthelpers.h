#ifndef SORTHELPERS_H
#define SORTHELPERS_H

/**
 * Returns 1 if first value is less than second_value, else 0.
 *
 */
int sorthelpers_less(int first_value, int second_value);

/**
 * Exchanges the values between the two indices of the array.
 * 
 */
void sorthelpers_exchange(int *array, int first_index, int second_index);

/**
 * Prints inline the given array.
 * 
 */
void sorthelpers_show(int *array, int length);

/**
 * Returns 1 if array is sorted else 0.
 * 
 */
int sorthelpers_is_sorted(int *array, int length);

/**
 * Merges sorted sub-arrays array[lo..mid] with array[mid+1..hi].
 * 
 */
void sorthelpers_merge(int *array, int *aux, int lo, int mid, int hi);

/**
 * Returns the minimum value between the two integer inputs.
 * 
 */
int sorthelpers_min(int first_value, int second_value);

/**
 * Shuffles the given array.
 * 
 */
void sorthelpers_shuffle(int *array, int length);

#endif