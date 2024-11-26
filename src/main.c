/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:43:36 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/26 20:25:43 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_fd(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		display_error();
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
	data->colors_map = params->colors_map;
	data->n_rows = params->n_rows;
	data->n_cols = params->n_cols;
	data->zoom = ZOOM;
	data->x_offset = WIN_WIDTH / 8;
	data->y_offset = WIN_HEIGHT / 2;
}

/***
 * @note we use two structures:
 * params: to store the values from the file
 * data: to store the infos about the mlx and window
 * 
 * This is the main function of the program
 * It will follow the following steps:
 * 1. Check the number of arguments
 * 2. Get the file name from the arguments
 * 3. Get the file descriptor using the file name
 * 4. Get the grid size from the file using getnextline
 * 5. Close the file descriptor because we have already 
 * 	read it till the end
 * 6. Get the file descriptor again so we can read it from 
 * 	the beginning again
 * 7. Parse the file and fill the struct params
 * 8. If the map or the colors_map are NULL, then free, 
 * 	display an error and exit
 * 9. Fill the data struct with the values from the params struct 
 * 	(the MLX_INIT is done here)
 * 10. Render the map
 * 11. Handle the keypress event and the destroy event
 * 12. Loop the mlx so the window stays open
 * 13. Close the file descriptor and free the maps
 */
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
	if (!params.map || !params.colors_map)
	{
		close(fd);
		free_all_maps(&data, &params);
		display_error();
	}
	fill_data(&data, &params);
	render_map(&data);
	mlx_hook(data.win_ptr, 2, 1L << 0, handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0L, handle_destroy, &data);
	mlx_loop(data.mlx_ptr);
	close(fd);
	free_all_maps(&data, &params);
}
