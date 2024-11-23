/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char_occurrences.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:48:49 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/23 17:49:15 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_char_occurrences(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}
