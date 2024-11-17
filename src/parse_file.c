/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:43:30 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/17 19:50:23 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// The test file must endup with a newline character
t_point	**parse_file(int fd, size_t n_rows, size_t n_cols)
{
	// ft_printf("fd in parse: %d\n", fd);
	char *line = get_next_line(fd);

	t_point **map = NULL;
	size_t i = 0;
	size_t j;

	size_t zoom_coeff = 2;
	size_t step_x = WIN_WIDTH / (zoom_coeff * (MAX(n_rows, n_cols) - 1));
	size_t step_y = WIN_HEIGHT / (zoom_coeff * (MAX(n_rows, n_cols) - 1));
	size_t step_z = 2; //(size_t) (MIN(step_x, step_y) / 10);

	char **values = NULL;
	ft_printf("n_rows: %d --- n_cols: %d\n", (int)n_rows, (int)n_cols);
	// Create a Map
	map = create_map(n_rows, n_cols);
	// ft_printf("map created\n");
	while (line && i < n_rows)
	{
		ft_printf("i: %d\n", (int)i);
		ft_printf("line: |%s|\n", line);
		values = ft_split(line, ' ');
		for (j = 0; j < n_cols; j++)
		{
			map[i][j].x = -1 * i * step_x;
			map[i][j].y = j * step_y;
			map[i][j].z = ft_atoi(values[j]) * step_z;
		}
		i++;
		free(line); // checked
		free_ft_split(values);

		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (map);
}