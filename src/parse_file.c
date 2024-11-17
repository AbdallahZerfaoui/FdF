#include "../includes/fdf.h"

t_point **parse_file(int fd, size_t n_rows, size_t n_cols)
{
	// ft_printf("fd in parse: %d\n", fd);
    char *line = get_next_line(fd);
    
    t_point **map = NULL;
    // size_t n_rows;
    // size_t n_cols;
    // get_grid_size(fd, &n_rows, &n_cols);
	// ft_printf("fd in parse: %d\n", fd);
	// ft_printf("Xncols: %d\n", (int)n_cols);
	// ft_printf("Xnrows: %d\n", (int)n_rows);
    size_t i = n_rows;
    size_t j;
    char **values = NULL;
	// ft_printf("n_rows: %d\n", (int)n_rows);
    // Create a Map
    map = create_map(n_rows, n_cols);
	// ft_printf("map created\n");
    while(line && i > 0)
    {
		// ft_printf("i: %d\n", (int)i);
        values = ft_split(line, ' ');
        for (j = 0; j < n_cols; j++)
        {
            map[i-1][j].x = 0;
            map[i-1][j].y = 0;
            map[i-1][j].z = ft_atoi(values[j]);
        }
        i--;
        free(line);
		free_ft_split(values);
        line = get_next_line(fd);
    }
    return map;
}