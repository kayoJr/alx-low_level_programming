#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - function to multiply two positive numbers together
 * @argc: number of arguments passed to function, including name
 *
 * @argv: array of arguments passed to function
 *
 * Return: 0 if successful, 98 if failed
 */

int main(int argc, char *argv[])
{
	unsigned long int num1, num2, product;
	int digit;
	char *array;
	char *errorarray = "Error";

	if (argc != 3)
	{
		error(errorarray);
		exit(98);
	}
	if (digit_check(argv[1]) == 0 || digit_check(argv[2]) == 0)
	{
		error(errorarray);
		exit(98);
	}
	else
	{
		num1 = a_to_int(argv[1]);
		num2 = a_to_int(argv[2]);
	}
	product = num1 * num2;
	digit = digit_size(product, 1);
	array = malloc(digit * sizeof(char) + 1);
	if (array == NULL)
	{
		error(errorarray);
		exit(98);
	}
	array = int_to_a(product, array, digit);
	print_array(array);
	free(array);
	return (0);
}

/**
 * error - function to print Error and exit with 98 if program fails
 * @array: character array to print
 *
 */

void error(char *array)
{
	int i = 0;

	for (i = 0; array[i]; i++)
		_putchar(array[i]);
	_putchar('\n');
}

/**
 * digit_check - checks if number is composed of only digits
 * @num: character pointer to argument
 *
 * Return: 1 if all digits and 0 if not a digit
 */

int digit_check(char *num)
{
	int i;

	for (i = 0; num[i]; i++)
	{
		if (num[i] >= '0' && num[i] <= '9')
			continue;
		else
			return (0);
	}
	return (1);
}

/**
 * a_to_int - changes digit characters to int
 * @s: array of characters
 *
 * Return: integer value of characters
 */

unsigned long int a_to_int(char *s)
{
	int i = 0, size = 0, place = 1;
	unsigned long int num = 0;

	for (i = 0; s[i]; i++, size++)
		continue;
	for (i = (size - 1); i >= 0; i--)
	{
		num += ((s[i] - '0') * place);
		place *= 10;
	}
	return (num);
}

/**
 * digit_size - determines how many digits make up a number
 * @num: input number
 *
 * @digits: input digit counter
 *
 * Return: number of digit places
 */

int digit_size(unsigned long int num, int digits)
{
	while (num / 10 != 0)
	{
		digits++;
		num /= 10;
	}
	return (digits);
}

/**
 * int_to_a - changes integer to character array
 * @num: input integer
 *
 * @s: input string to assign character value of num to
 *
 * @digits: input number of digits
 *
 * Return: array of characters representing number
 */

char *int_to_a(unsigned long int num, char *s, int digits)
{
	int i = 0;

	for (i = (digits - 1); i >= 0; i--)
	{
		s[i] = (num % 10) + '0';
		num /= 10;
	}
	s[digits] = '\0';
	return (s);
}

/**
 * print_array - prints array of characters
 * @s: array of characters
 *
 */

void print_array(char *s)
{
	int i = 0;

	for (i = 0; s[i]; i++)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
