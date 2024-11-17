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

	close(fd);
	fd = open(file_name, O_RDONLY);

	// Parse the file
	t_point **map = parse_file(fd, n_rows, n_cols);
	if (!map)
	{
		ft_printf("Error\n");
		return 1;
	}
	// ft_printf("Parsing Done\n");
	for (size_t i = n_rows - 1; i < n_rows; i--)
	{
		for (size_t j = 0; j < n_cols; j++)
		{	
			if (j == n_cols - 1)
				ft_printf("%d", map[i][j].z);
			else
				ft_printf("%d ", map[i][j].z);
		}
		ft_printf("\n");
	}
	close(fd);
	free_map(map, n_rows);
	return 0;
}