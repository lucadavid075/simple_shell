#include "shellheader.h"

/**
*_strlen - Return the lenght of a string
*@s: name of the pointer
*Return: lenght of the string
*/

size_t _strlen(const char *s)
{
	size_t len = 0;

	while (*s != 0)
	{
		s++;
		len++;
	}

	return (len);
}
