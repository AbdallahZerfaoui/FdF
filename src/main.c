/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:43:36 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/17 21:07:01 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

static void	handle_inputs(int argc)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <file.fdf>\n");
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	char	*file_name;
	int		fd;
	t_map_params	params;
	// size_t	n_rows;
	// size_t	n_cols;
	// t_point	**map;
	t_data	data;

	handle_inputs(argc);
	file_name = argv[1];
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	get_grid_size(fd, &params.n_rows, &params.n_cols);
	close(fd);
	fd = open(file_name, O_RDONLY);
	parse_file(fd, &params);
	if (!params.map)
	{
		ft_printf("Error\n");
		return (1);
	}
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	data.map = params.map;
	data.n_rows = params.n_rows;
	data.n_cols = params.n_cols;
	data.zoom = 1;
	data.x_offset = WIN_WIDTH / 8;
	data.y_offset = WIN_HEIGHT / 2;
	// Render the map
	render_map(&data);
	// MiniLibX event loop to keep the window open
	mlx_loop(data.mlx_ptr);
	close(fd);
	free_map(params.map, params.n_rows);
	return (0);
}
