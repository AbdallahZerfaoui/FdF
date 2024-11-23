/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:34:00 by azerfaou          #+#    #+#             */
/*   Updated: 2024/10/25 13:26:03 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_num_digits(long long num)
{
	size_t	nbr_digits;

	nbr_digits = 1;
	if (num < 0)
		nbr_digits++;
	num = num / 10;
	while (num != 0)
	{
		num = num / 10;
		nbr_digits++;
	}
	return (nbr_digits);
}

size_t	ft_ptrlen(void *ptr)
{
	size_t	len;

	len = 2;
	while (ptr != 0)
	{
		ptr = (void *)((unsigned long long)ptr / 16);
		len++;
	}
	return (len);
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	size;

// 	size = 0;
// 	while (*s)
// 	{
// 		size++;
// 		s++;
// 	}
// 	return (size);
// }
