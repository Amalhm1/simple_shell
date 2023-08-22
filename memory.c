#include "shell.h"

/**
 * bfree - frees the pointer and NULLs the add
 * @ptr: The address of the point to be freed
 *
 * Return: If freed 1, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
