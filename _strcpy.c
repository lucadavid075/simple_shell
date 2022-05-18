#include "shellheader.h"

/**
*_strcpy - function to copy an string
*@dest: name of the pointer
*@src: name of the pointer
*Return: what is inside *dest
*/

char *_strcpy(char *dest, char *src)
{
	int x;

	for (x = 0; src[x] != '\0'; x++)
	{
		dest[x] = src[x];
	}
		dest[x] = '\0';

return (dest);
}
