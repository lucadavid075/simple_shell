#include "shellheader.h"

/**
 * _strncmp - function to compare strings until an n index
 * @s1: string 1
 * @s2: string 2
 * @n: index
 * Return: result of s1 - s2
*/

int _strncmp(const char *s1, const char *s2, int n)
{
	int i, res = 0;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

return (res);
}
