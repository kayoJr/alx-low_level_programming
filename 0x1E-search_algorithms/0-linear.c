#include "search_algos.h"

/**
 * linear_search - searches for a value in an array of integers
 * @array: array of integers, pointer to the first element
 * @size: the number of elements in the array
 * @value: value to search for
 * Return: integer value found or -1 if not found
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL || size == 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%i] = [%i]\n", (int)i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
