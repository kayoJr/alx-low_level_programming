#ifndef MAIN_H
#define MAIN_H

/* declaration of function to allocate specified size of memory (0)*/
void *malloc_checked(unsigned int b);

/* declaration of function to point to concatenated strings up to n bytes (1)*/
char *string_nconcat(char *s1, char *s2, unsigned int n);

/* declaration of subfunction to find string length (1)*/
unsigned int _strlen(char *s);

/* declaration of function to allocate memory for an array and set to 0 (2)*/
void *_calloc(unsigned int nmemb, unsigned int size);

/* declaration of function to allocate array of ints from min to max (3)*/
int *array_range(int min, int max);

/* declaration of function to reallocate memory (4)*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*declaration of subfunction to print error if failed (5)*/
void error(char *array);

/*declaration of subfunction to check if char of arguments are digits (5)*/
int digit_check(char *num);

/*declaration of subfunction to change character into integer (5)*/
unsigned long int a_to_int(char *s);

/*declaration of subfunction to determine how many digits a number has (5)*/
int digit_size(unsigned long int num, int digits);

/* declaration of subfunction to change interger into character array (5)*/
char *int_to_a(unsigned long int num, char *s, int digits);

/* declaration of subfunction to print array of characters (5)*/
void print_array(char *s);

/* declaration of putchar function */
int _putchar(char c);

#endif
