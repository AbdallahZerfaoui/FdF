/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:47:22 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/25 13:04:19 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	display_hex(void *ptr, int fd)
{
	static int			count;
	unsigned long long	n;
	char				*base;
	ssize_t				result;

	count = 1;
	n = (unsigned long long)ptr;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		if (display_hex((void *)(n / 16), fd) == -1)
			return (-1);
		count += 1;
	}
	result = write(fd, base + n % 16, 1);
	if (result == -1)
		return (-1);
	return (count);
}

int	ft_putptr_fd_pf(void *ptr, int fd)
{
	int		count;
	ssize_t	result;

	result = ft_putstr_fd_pf("0x", fd);
	if (result == -1)
		return (-1);
	count = display_hex(ptr, fd);
	return (count + 2);
}
