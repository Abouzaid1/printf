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
			_putchar(format[i]);
			break;
		}
		else if (format[i + 1] == 'c')
		{
			_putchar(va_arg(args, int));
			i++;
			break;
		}
		else if (format[i + 1] == 's')
		{
			s_count = _puts(va_arg(args, char *));
			i++;
			count += (s_count - 1);
			break;
		}
		else if (format[i+1] == '%')
		{
			_putchar('%');
			i++;
			break;
		}
		
		count += 1;
		}
	va_end(args);
	return (count);
}
