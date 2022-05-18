#include "shellheader.h"

/**
*_strcat - function that concatenate 2 strings
*@dest: name of the first pointer
*@src: name of the second pointer
*Return: pointer that points to the memory address where is the value of dest
*/

char *_strcat(char *dest, char *src)
{
	int x;
	int k;

	/*to find lenght of dest*/
	x = 0;
	while (dest[x] != '\0')
	{
		x++;
	}

	/*append src to dest*/
	for (k = 0; src[k] != '\0'; k++)
	{
		dest[x + k] = src[k];
	}

	/*add the null to dest*/
		dest[x + k] = '\0';

return (dest);
}
