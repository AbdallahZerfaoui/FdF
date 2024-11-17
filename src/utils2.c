/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:08:08 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/17 20:08:28 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	min_map(t_point **map, size_t n_rows, size_t n_cols)
{
	int		min;
	size_t	i;
	size_t	j;

	min = INT_MAX;
	i = 0;
	j = 0;
	while (i < n_rows)
	{
		while (j < n_cols)
		{
			if (map[i][j].z < min)
				min = map[i][j].z;
			j++;
		}
		i++;
	}
	return (min);
}

int	max_map(t_point **map, size_t n_rows, size_t n_cols)
{
	int		max;
	size_t	i;
	size_t	j;

	max = INT_MIN;
	i = 0;
	j = 0;
	while (i < n_rows)
	{
		while (j < n_cols)
		{
			if (map[i][j].z > max)
				max = map[i][j].z;
			j++;
		}
		i++;
	}
	return (max);
}
