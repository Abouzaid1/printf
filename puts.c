#include "main.h"
/**
 * puts - print a string
 * @s: str input
 * Return: number of bytes
 */
int puts(char *c)
{
	int count = 0;
	if (c)
	{
		for (count = 0; c[count] != '\0'; count++)
		{
			putchar(c[count]);
		}
	}
	return (count);
}
