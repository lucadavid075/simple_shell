#include "shellheader.h"
/**
 * split_path - function to split env variable PATH into tokens
 * @path: pointer holding PATH
 * Return: Pointer to an array of strings holding the tokens
*/
char **split_path(char *path)
{
	unsigned int i;
	char *tok = NULL, **dir;
	size_t dir_size = 32;

	dir = malloc(sizeof(char *) * dir_size);
	if (dir == NULL)
	{
		perror("split_path: failed to allocate dir\n");
		exit(EXIT_FAILURE);
	} tok = strtok(path, "= :");
	tok = strtok(NULL, "= :");
	if (tok == NULL)
	{
		free(dir);
		perror("Please enter a path\n");
		exit(EXIT_FAILURE);
	} else
	{
		i = 0;
		while (tok != NULL)
		{
			dir[i] = malloc(sizeof(char) * (_strlen(tok) + 2));
			if (dir[i] == NULL)
			{
				free(dir);
				perror("hsh: failed to allocate dir[i]\n");
				exit(EXIT_FAILURE);
			} _strcpy(dir[i], tok);
			_strcat(dir[i], "/");
			tok = strtok(NULL, "= :");
			i++;
			if (i >= dir_size)
			{
				dir_size += 32;
				dir = _realloc(dir, dir_size, dir_size * sizeof(char *));
				if (dir == NULL)
				perror("hsh: failed to reallocate dir\n");
			}
		} dir[i] = NULL;
	} return (dir);
}
