#include "shellheader.h"

/**
 * read_command - read the command that the user will type
 * in my shell and stores it in a buffer
 * Return: the buffer
*/

char *read_command(void)
{
	size_t linesize = 32;
	char *line = NULL;

	line = malloc(sizeof(char) * linesize);
	if (getline(&line, &linesize, stdin) == EOF)
	{
		/*write(STDOUT_FILENO, "\n", 1);*/
		free(line);
		exit(0);
	}

return (line);
}
