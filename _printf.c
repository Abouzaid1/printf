#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...) {
    int count = 0; 

    va_list args;
    va_start(args, format);
	
    while (*format) {
        if (*format == '%') {
            format+=1;  
            switch (*format) {
                case 'c':
                    _putchar(va_arg(args, int));
                    count+=1;
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    _putchar('%');
                    count+=1;
                    break;
                default:
                    
                    _putchar('%');
                    _putchar(*format);
                    count += 2;
                    break;
            }
        } else {
            _putchar(*format);
            count+=1;
        }
        format++;
    }

    va_end(args);
    return count;
}