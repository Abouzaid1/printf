#include "main.h"
/**
 * __putchr - print a char
 * @c: char input
 * Return: 1
 */
int __putchr(char c)
{
	return (write(1, &c, 1));
}
