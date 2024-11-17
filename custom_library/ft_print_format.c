#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "../includes/libftprintf.h"
#include "../includes/libft.h"

int print_format(char specifier, va_list args)
{
    if (specifier == 'c')
        ft_putchar_fd(va_arg(args, int), 1);
    else if (specifier == 's')
        ft_putstr_fd(va_arg(args, char *), 1);
    else if (specifier == 'p')
        ft_putptr_fd(va_arg(args, void *), 1);
    else if (specifier == 'd' || specifier == 'i')
    {
        ft_putnbr_fd(va_arg(args, int), 1);
    }
    else if (specifier == 'u')
        ft_putunbr_fd(va_arg(args, unsigned int), 1);
    else if (specifier == 'x')
        ft_puthex_fd(va_arg(args, unsigned int), 1);
    else if (specifier == 'X')
        ft_puthex_upper_fd(va_arg(args, unsigned int), 1);
    else if (specifier == '%')
        ft_putchar_fd('%', 1);
    return 0;
}