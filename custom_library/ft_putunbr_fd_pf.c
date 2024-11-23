/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:51:47 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/25 13:04:19 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putunbr_fd_pf(long long n, int fd)
{
	int		count;
	ssize_t	result;

	count = ft_num_digits((unsigned int)n);
	if (n >= 10)
	{
		if (ft_putunbr_fd_pf(n / 10, fd) == -1)
			return (-1);
	}
	result = ft_putchar_fd_pf("0123456789"[n % 10], fd);
	if (result == -1)
		return (-1);
	return (count);
}
