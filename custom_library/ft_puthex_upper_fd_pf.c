/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper_fd_pf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:46:54 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/25 13:04:19 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_puthex_upper_fd_pf(unsigned int n, int fd)
{
	char		*base;
	static int	count;
	ssize_t		result;

	count = 1;
	base = "0123456789ABCDEF";
	n = (unsigned int)n;
	if (n >= 16)
	{
		if (ft_puthex_upper_fd_pf(n / 16, fd) == -1)
			return (-1);
		count += 1;
	}
	result = ft_putchar_fd_pf(base[n % 16], fd);
	if (result == -1)
		return (-1);
	return (count);
}
