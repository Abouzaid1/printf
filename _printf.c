#include "main.h"
/**
 * _printf - print to stdout formatted text
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

	if (!format || (format[0] == '%' && format[1] == '\0')) 
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
		}
		else if (format[i + 1] == 'c')
		{
			putchar(va_arg(args, int));
			i++;
		}
		else if (format[i + 1] == 's')
		{
			s_count = puts(va_arg(args, char *));
			i++;
			count += (s_count - 1);
		}
		else if (format[i+1] == '%')
		{
			putchar('%');
			i++;
		}
		count += 1;
		}
	va_end(args);
	return (count);
}
