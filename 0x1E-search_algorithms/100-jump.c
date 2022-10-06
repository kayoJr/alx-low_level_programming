#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for a value in an sorted array of integers
 * @array: array of integers, pointer to the first element
 * @size: the number of elements in the array
 * @value: value to search for
 * Return: index value found or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	int next = 0;
	int prev = 0;
	int jump = 0;

	if (array == NULL || size <= 0)
		return (-1);

	jump = sqrt(size);

	for (; array[next] < value && next < (int)size; next = next + jump)
	{
		printf("Value checked array[%i] = [%i]\n", next, array[next]);
		prev = next;
	}
	printf("Value found between indexes [%i] and [%i]\n", prev, next);
	while (prev <= next && prev < (int)size)
	{
		printf("Value checked array[%i] = [%i]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
		prev = prev + 1;
	}
	return (-1);
}
