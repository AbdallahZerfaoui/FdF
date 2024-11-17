/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:43:30 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/17 20:22:23 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// The test file must endup with a newline character
t_point	**parse_file(int fd, size_t n_rows, size_t n_cols)
{
	char			*line;
	t_map_params	params;
	// t_point	**map;
	size_t	i;
	size_t	j;
	// size_t	zoom_coeff;
	// size_t	step_x;
	// size_t	step_y;
	// size_t	step_z;
	// char	**values;

	// ft_printf("fd in parse: %d\n", fd);
	params.n_rows = n_rows;
	params.n_cols = n_cols;
	line = get_next_line(fd);
	params.map = NULL;
	i = 0;
	params.zoom_coeff = 2;
	params.step_x = WIN_WIDTH / (params.zoom_coeff * (MAX(n_rows, n_cols) - 1));
	params.step_y = WIN_HEIGHT / (params.zoom_coeff * (MAX(n_rows, n_cols) - 1));
	params.step_z = 2;
	params.values = NULL;
	ft_printf("n_rows: %d --- n_cols: %d\n", (int)n_rows, (int)n_cols);
	params.map = create_map(n_rows, n_cols);
	while (line && i < n_rows)
	{
		ft_printf("i: %d\n", (int)i);
		ft_printf("line: |%s|\n", line);
		params.values = ft_split(line, ' ');
		for (j = 0; j < n_cols; j++)
		{
			params.map[i][j].x = -1 * i * params.step_x;
			params.map[i][j].y = j * params.step_y;
			params.map[i][j].z = ft_atoi(params.values[j]) * params.step_z;
		}
		i++;
		free(line);
		free_ft_split(params.values);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (params.map);
}
