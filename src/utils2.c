/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:08:08 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/26 13:12:09 by azerfaou         ###   ########.fr       */
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
	while (i < n_rows)
	{
		j = 0;
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
	while (i < n_rows)
	{
		j = 0;
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

void	free_ft_split(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_all_maps(t_data *data, t_map_params *params)
{
	if (params->map)
		free_map((void **)params->map, params->n_rows);
	if (data->map)
		free_map((void **)data->map, data->n_rows);
	if (params->colors_map)
		free_map((void **)params->colors_map, params->n_rows);
	if (data->colors_map)
		free_map((void **)data->colors_map, data->n_rows);
}
