#include "../includes/libft.h"

char *ft_itoa(int value)
{
    static char buffer[12];
    char *end_ptr;
    int sign;

    end_ptr = &buffer[11];
    *end_ptr = '\0';
    sign = (value < 0) ? -1 : 1;
    if (value == 0)
    {
        *--end_ptr = '0';
        return (end_ptr);
    }
    while (value != 0)
    {
        *--end_ptr = '0' + (value % 10) * sign;
        value /= 10;
    }
    if (sign == -1)
        *--end_ptr = '-';
    return (end_ptr);
}
