#include "shellheader.h"

/**
 * free_double_pointer - function to free a pointer to an array of strings
 * @directories: pointer to an array of strings
 * Return: nothing, always success
*/

void free_double_pointer(char **directories)
{
	int i;

	for (i = 0; directories[i]; i++)
	{
		free(directories[i]);
	}

	free(directories);
}
