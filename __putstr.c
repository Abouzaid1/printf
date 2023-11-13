#include "main.h"
/**
 * __putstr - print a string
 * @s: str input
 * Return: number of bytes
 */
int __putstr(char *c)
{
    int count = 0;
    if (c)
    {
        for (count = 0; c[count] != '\0'; count++)
        {
            __putchr(c[count]);
        }
    }
    return (count);
}