/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:00:26 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/19 14:14:28 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @note the buffer is 19 digits + 1 sign + 1 null terminator
 */
char	*ft_itoa_long(long value)
{
	static char	buffer[21];
	char		*end_ptr;
	int			sign;

	end_ptr = &buffer[11];
	*end_ptr = '\0';
	sign = 1;
	if (value < 0)
		sign = -1;
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
