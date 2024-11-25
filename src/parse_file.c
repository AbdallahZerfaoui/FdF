/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:43:30 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/25 19:09:03 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_map_params(t_map_params *params)
{
	params->map = NULL;
	params->zoom_coeff = 2;
	params->step_x = WIN_WIDTH / (params->zoom_coeff * (ft_max(params->n_rows,
					params->n_cols) - 1));
	params->step_y = WIN_HEIGHT / (params->zoom_coeff * (ft_max(params->n_rows,
					params->n_cols) - 1));
	params->step_z = STEP_Z;
	params->values = NULL;
}

/**
 * @brief Process the map element and fill the map with z value and colors_map
 * @note this function is called in fill_maps
 * i have created it to make the code more readable ans shorter
 */
static void	process_map_element(t_map_params *params,
				size_t i, size_t j)
{
	char	**map_element;
	int		z;

	map_element = ft_split(params->values[j], ',');
	z = ft_atoi(map_element[0]);
	params->map[i][j].x = -1 * i * params->step_x;
	params->map[i][j].y = j * params->step_y;
	params->map[i][j].z = z * params->step_z;
	if (map_element[1] == NULL)
	{
		params->colors_map[i][j] = get_color(params->map[i][j].z, params);
	}
	else
		params->colors_map[i][j] = ft_atoi_base(map_element[1] + 2, 16);
	free_ft_split(map_element);
}

/**
 * @brief Fill the map with the values from the file
 * @note the +2 in map_element[1] is to skip the "0x" in the hexadecimal color
 */
static void	fill_maps(t_map_params *params, int fd)
{
	char	*line;
	size_t	i;
	size_t	j;

	line = get_next_line(fd);
	i = 0;
	while (line && i < params->n_rows)
	{
		j = 0;
		params->values = ft_split(line, ' ');
		while (j < params->n_cols)
		{
			process_map_element(params, i, j);
			j++;
		}
		i++;
		free(line);
		free_ft_split(params->values);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
}

/*
 *@note The test file must endup with a newline character
 */
void	parse_file(int fd, t_map_params *params)
{
	init_map_params(params);
	params->map = create_map(params->n_rows, params->n_cols);
	params->colors_map = create_colors_map(params->n_rows, params->n_cols);
	fill_maps(params, fd);
}
