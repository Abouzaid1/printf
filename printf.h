#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;  // To keep track of the number of characters printed

    while (*format) {
        if (*format == '%') {
            format++;  // Move past '%'
            switch (*format) {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    // Handle unsupported specifier
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}

int main() {
    _printf("I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life.\n");
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello, World!");
    _printf("Percentage: %%\n");

    return 0;
}
