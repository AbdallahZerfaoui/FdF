/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:47:08 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/25 13:04:19 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
* @brief This function will print a positive number to the given file descriptor.
 */
static int	putposnbr_fd_pf(int n, int fd)
{
	int		nbr_digits;
	ssize_t	result;

	nbr_digits = ft_num_digits(n);
	if (n > 9)
	{
		if (putposnbr_fd_pf(n / 10, fd) == -1)
			return (-1);
		if (putposnbr_fd_pf(n % 10, fd) == -1)
			return (-1);
	}
	else
	{
		n = n + '0';
		result = ft_putchar_fd_pf(n, fd);
		if (result == -1)
			return (-1);
	}
	return (nbr_digits);
}

int	ft_putnbr_fd_pf(int n, int fd)
{
	int		count;
	ssize_t	result;

	count = 0;
	if (n == INT_MIN)
	{
		result = ft_putstr_fd_pf("-2147483648", fd);
		if (result == -1)
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		result = ft_putchar_fd_pf('-', fd);
		if (result == -1)
			return (-1);
		n = -n;
		count = 1;
	}
	count += putposnbr_fd_pf(n, fd);
	return (count);
}
