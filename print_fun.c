#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints a formatted string to the standard output
 * @format: the format string to print
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
        va_list args;
        int count = 0;

        va_start(args, format);

        while (*format)
        {
                /* Print plain text */
                if (*format != '%')
                {
                        putchar(*format);
                        count++;
                }
                else
                {
                        format++;
                        /* Print character argument */
                        if (*format == 'c')
                        {
                                char c = va_arg(args, int);
                                putchar(c);
                                count++;
                        }
                        /* Print string argument */
                        else if (*format == 's')
                        {
                                char *str = va_arg(args, char *);
                                int len = 0;
                                while (str[len])
                                {
                                        putchar(str[len]);
                                        len++;
                                        count++;
                                }
                        }
                        /* Print percent sign */
                        else if (*format == '%')
                        {
                                putchar('%');
                                count++;
                        }
                        /* Print decimal integer argument */
                        else if (*format == 'd' || *format == 'i')
                        {
                                int num = va_arg(args, int);
                                if (num < 0)
                                {
                                        putchar('-');
                                        count++;
                                        num = -num;
                                }
                                int digit_count = 1;
                                int temp = num;
                                while (temp > 9)
                                {
                                        digit_count *= 10;
                                        temp /= 10;
                                }
                                while (digit_count > 0)
                                {
                                        putchar(num / digit_count + '0');
                                        count++;
                                        num %= digit_count;
                                        digit_count /= 10;
                                }
                        }
                        /* Unsupported format specifier */
                        else
                        {
                                putchar('%');
                                putchar(*format);
                                count += 2;
                        }
                }
                format++;
        }

        va_end(args);

        return count;
}
