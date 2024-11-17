#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include "../includes/libftprintf.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int count = 0;
    while (*format != '\0') 
    {
        if (*format != '%') 
            ft_putchar_fd(*format, 1);
        else 
        {           
            format++;
            count += print_format(*format, args);
        }
        format++;
    }
    va_end(args);
    return count;
}
