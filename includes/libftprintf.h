#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "libft.h"
#include <stdarg.h>


// ft_printf Helper functions
int ft_printf(const char *format, ...);
int print_format(char specifier, va_list args);

#endif
