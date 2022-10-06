#include "search_algos.h"

/**
 * binary_search - searches for a value in an sorted array of integers
 * @array: array of integers, pointer to the first element
 * @size: the number of elements in the array
 * @value: value to search for
 * Return: index value found or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	int left = 0;
	int right = (int)size - 1;
	int middle = 0;
	int start = 0;

	if (array == NULL || size == 0)
		return (-1);

	while (left <= right)
	{
		start = left;
		printf("Searching in array: ");
		middle = (left + right) / 2;
		for (; start < right; start++)
			printf("%i, ", array[start]);
		printf("%i\n", array[start]);
		if (array[middle] == value)
			return (middle);
		else if (value > array[middle])
			left = middle + 1;
		else
			right = middle - 1;
	}
	return (-1);
}
