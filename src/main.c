#include "../includes/fdf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <file.fdf>\n");
		return 1;
	}

	char *file_name = argv[1];
	int fd = open(file_name, O_RDONLY);
	size_t n_rows;
	size_t n_cols;

	get_grid_size(fd, &n_rows, &n_cols);
	// ft_printf("n_rows: %d--- n_cols: %d\n", (int)n_rows, (int)n_cols);

	// size_t step_x = WIN_WIDTH / (n_cols - 1);
	// size_t step_y = WIN_HEIGHT / (n_rows - 1);
	
	close(fd);
	fd = open(file_name, O_RDONLY);

	// Parse the file
	t_point **map = parse_file(fd, n_rows, n_cols);
	if (!map)
	{
		ft_printf("Error\n");
		return 1;
	}
	t_data data;
	// ft_printf("Parsing Done\n");
	// for (size_t i = n_rows - 1; i < n_rows; i--)
	// {
	// 	for (size_t j = 0; j < n_cols; j++)
	// 	{	
	// 		if (j == n_cols - 1)
	// 			ft_printf("%d", map[i][j].x);
	// 		else
	// 			ft_printf("%d ", map[i][j].x);
	// 	}
	// 	ft_printf("\n");
	// }

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	data.map = map;
	data.n_rows = n_rows;
	data.n_cols = n_cols;
	data.zoom = 1; //(int) MIN(WIN_WIDTH / (n_cols - 1), WIN_HEIGHT / (n_rows - 1));
	data.x_offset = WIN_WIDTH / 8;
	data.y_offset = WIN_HEIGHT / 2;	

	// Render the map
	render_map(&data);

	// MiniLibX event loop to keep the window open
    mlx_loop(data.mlx_ptr);

	close(fd);
	free_map(map, n_rows);
	return 0;
}