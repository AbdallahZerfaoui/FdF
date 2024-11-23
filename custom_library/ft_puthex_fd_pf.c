/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:46:50 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/25 13:04:19 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/**
 * @brief Print an hexadecimal number to a file descriptor
 * If the number is negative, it will be casted to an unsigned int
 * n is long long to handle the maximum value of an unsigned int
 */

int	ft_puthex_fd_pf(long long n, int fd)
{
	char		*base;
	static int	count;
	ssize_t		result;

	count = 1;
	base = "0123456789abcdef";
	n = (unsigned int)n;
	if (n >= 16)
	{
		if (ft_puthex_fd_pf(n / 16, fd) == -1)
			return (-1);
		count += 1;
	}
	result = ft_putchar_fd_pf(base[n % 16], fd);
	if (result == -1)
		return (-1);
	return (count);
}
