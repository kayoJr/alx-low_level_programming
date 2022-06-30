#include "hash_tables.h"

/**
 * shash_table_create - creates a hash table
 * @size: the size of the hash table
 *
 * Return: pointer to the hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;

	if (!size)
		return (NULL);

	ht = calloc(1, sizeof(shash_table_t));
	if (!ht)
		return (NULL);

	ht->size = size;

	ht->array = calloc(size, sizeof(shash_node_t *));
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}
	return (ht);
}


/**
 * shash_table_set - adds an element to a hash table
 * @ht: pointer to the shash table to add or update the key/value to
 * @key: the string key, cannot be an empty string
 * @value: the string value, can be an empty string
 *
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	char *valueCpy;
	shash_node_t *new, *search = NULL;
	unsigned long int idx;

	if (!ht || !key || !*key || !value)
		return (0);
	valueCpy = strdup(value);
	if (!valueCpy)
		return (0);
	idx = key_index((unsigned char *)key, ht->size);
	search = ht->array[idx];

	while (search)
	{
		if (!strcmp(key, search->key))
		{
			free(search->value);
			search->value = valueCpy;
			return (1);
		}
		search = search->next;
	}

	new = malloc(sizeof(hash_node_t));
	if (!new)
	{
		free(valueCpy);
		return (0);
	}
	new->key = strdup(key);
	if (!new->key)
	{
		free(new);
		return (0);
	}

	new->value = valueCpy;
	new->next = ht->array[idx];
	ht->array[idx] = new;
	return (1);
}

/**
 * shash_table_print - prints a hash table
 * @ht: the hash table to print
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;
	int first = 1;
	unsigned long idx;

	if (!ht)
		return;

	printf("{");
	for (idx = 0; idx < ht->size; idx++)
	{
		current = ht->array[idx];
		while (current)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", current->key, current->value);
			first = 0;
			current = current->next;
		}
	}

	printf("}\n");

}

/**
 * shash_table_get - retrieves a value associated with a key.
 * @ht: the hash table to look into
 * @key: the key to look for
 *
 * Return: the value associated, or NULL if the key couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *search = NULL;
	unsigned long int idx;

	if (!ht || !key || !*key)
		return (NULL);

	idx = key_index((unsigned char *)key, ht->size);
	search = ht->array[idx];

	while (search)
	{
		if (!strcmp(key, search->key))
		{
			return (search->value);
		}
		search = search->next;
	}
	return (NULL);
}


/**
 * shash_table_delete - deletes a hash table
 * @ht: the hash table to delete
 *
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current, *tmp;
	unsigned long int idx;

	if (!ht)
		return;

	for (idx = 0; idx < ht->size; idx++)
	{
		current = ht->array[idx];
		while (current)
		{
			tmp = current;
			current = current->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
	}
	free(ht->array);
	free(ht);
}
