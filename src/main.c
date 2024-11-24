/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:43:36 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/24 13:53:31 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	handle_inputs(int argc)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <file.fdf>\n");
		exit (1);
	}
}

static int	get_fd(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n");
		exit (1);
	}
	return (fd);
}

/**
 * fill the structure with the values from the map params
 * the map params are collected from a file
 */
void	fill_data(t_data *data, t_map_params *params)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	data->map = params->map;
	data->n_rows = params->n_rows;
	data->n_cols = params->n_cols;
	data->zoom = 1;
	data->x_offset = WIN_WIDTH / 8;
	data->y_offset = WIN_HEIGHT / 2;
}

int	main(int argc, char **argv)
{
	char			*file_name;
	int				fd;
	t_map_params	params;
	t_data			data;

	handle_inputs(argc);
	file_name = argv[1];
	fd = get_fd(file_name);
	get_grid_size(fd, &params.n_rows, &params.n_cols);
	close(fd);
	fd = get_fd(file_name);
	parse_file(fd, &params);
	if (!params.map)
	{
		ft_printf("Error\n");
		return (1);
	}
	fill_data(&data, &params);
	render_map(&data);
	mlx_loop(data.mlx_ptr);
	close(fd);
	free_map(params.map, params.n_rows);
	return (0);
}
