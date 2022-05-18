#include "shellheader.h"

/**
*_strcmp - function to compare two strings lexicographically
*@s1: name of the pointer 1
*@s2: name of the pointer 2
*Return: integer with the value of compare depeding the case
*/

int _strcmp(char *s1, char *s2)
{
	int x;
	int compare;

	for (x = 0; s1[x] != '\0'; x++)
	{
		if (s1[x] != s2[x])
		{
			compare = (s1[x] - s2[x]);
			break;
		}

		else if (s1[x] == s2[x])
		{
			if (s1[x] != s2[x])
			{
				compare = (s1[x] - s2[x]);
				break;
			}
		}

	}

compare = (s1[x] - s2[x]);

return (compare);
}
