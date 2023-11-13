#include "main.h"
/**
 * puts - print a string
 * @s: str input
 * Return: number of bytes
 */
int _puts(char *c)
{
	int count = 0;
	if (c)
	{
		for (count = 0; c[count] != '\0'; count++)
		{
			_putchar(c[count]);
		}
	}
	return (count);
}
