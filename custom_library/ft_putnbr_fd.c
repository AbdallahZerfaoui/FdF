#include "../includes/libft.h"

void putposnbr_fd(int n, int fd)
{
    if (n > 9)
    {
        putposnbr_fd(n / 10, fd);
        putposnbr_fd(n % 10, fd);
    }
    else
    {
        n = n + '0';
        write(fd, &n, 1);
    }
}

void ft_putnbr_fd(int n, int fd)
{
    if (n == INT_MIN)
    {
        write(fd, "-2147483648", 11);
        return;
    }
    if (n < 0)
    {
        write(fd, "-", 1);
        n = -n;
    }
    putposnbr_fd(n, fd);
}