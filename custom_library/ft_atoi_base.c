/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:48:10 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/24 18:49:30 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	get_digit(char c, int digits_in_base)
{
	int	max_digit;

	if (digits_in_base <= 10)
		max_digit = digits_in_base - 1 + '0';
	else
		max_digit = digits_in_base - 10 - 1 + 'a';
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');
	else
		return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	sign;
	int	digit;

	result = 0;
	sign = 1;
	if (str == NULL || str_base < 2 || str_base > 16)
		return (0);
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	while (*str)
	{
		digit = get_digit(ft_tolower(*str), str_base);
		if (digit == -1)
			break ;
		result = result * str_base + digit;
		++str;
	}
	return (result * sign);
}
