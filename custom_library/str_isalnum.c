/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_isalnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:20:34 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/19 13:29:48 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	str_isalnum(char *str)
{
	int	is_sign;

	if (!str)
		return (0);
	is_sign = 0;
	while (*str)
	{
		is_sign = (*str == '-' && !is_sign);
		if (!ft_isalnum(*str) && *str != ' ' && !is_sign)
			return (0);
		str++;
	}
	return (1);
}
// int	get_elems_nbr(char *str)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == ' ')
// 			count++;
// 		i++;
// 	}
// 	return (count + 1);
// }

// int	str_isalnum(char *str)
// {
// 	char	**nbrs_array;
// 	int		i;
// 	int		nbr;

// 	if (!str)
// 		return (1);
// 	nbrs_array = ft_split(str, ' ');
// 	i = 0;
// 	if (!nbrs_array)
// 		return (1);
// 	while (nbrs_array[i])
// 	{
// 		nbr = ft_atoi(nbrs_array[i]);
// 		if ()
// 		{
// 			free(nbrs_array);
// 			return (1);
// 		}
// 		i++;
// 	}
// }