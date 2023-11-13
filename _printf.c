#include "main.h"
/**
 * _printf - print to formatted text
 *
 * @format: formate specifier
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	unsigned int i, s_count;
	int count = 0;

	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			__putchr(format[i]);
		}
		else if (format[i + 1] == 'c')
		{
			__putchr(va_arg(args, int));
			i++;
		}
		else if (format[i + 1] == 's')
		{
			s_count = __putstr(va_arg(args, char *));
			i++;
			count += (s_count - 1);
		}
		else if (format[i] == '%')
		{
			__putchr('%');
			i++;
		}
		count += 1;
		}
	va_end(args);
	return count;
}