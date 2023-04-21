#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @a: pointer to first element
 * @b: pointer to second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - partitions an array according to Lomuto scheme
 * @array: array to partition
 * @size: size of array
 * @low: starting index of partition
 * @high: ending index of partition
 *
 * Return: index of pivot element
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
    int pivot = array[high];
    int i = low - 1, j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            if (i != j)
                print_array(array, size);
        }
    }
    swap(&array[i + 1], &array[high]);
    if (i + 1 != high)
        print_array(array, size);

    return i + 1;
}

/**
 * quicksort - sorts an array of integers using quicksort algorithm
 * @array: array to sort
 * @size: size of array
 * @low: starting index of partition
 * @high: ending index of partition
 */
void quicksort(int *array, size_t size, int low, int high)
{
    int pivot;

    if (low < high)
    {
        pivot = lomuto_partition(array, size, low, high);
        quicksort(array, size, low, pivot - 1);
        quicksort(array, size, pivot + 1, high);
    }
}

/**
 * quick_sort - sorts an array of integers in ascending order using the Quick
 *              sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, size, 0, size - 1);
}

