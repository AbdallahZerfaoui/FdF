#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "get_next_line.h"
#include "libftprintf.h"
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

typedef struct s_point
{
    int x;
    int y;
    int z;
} t_point;

// Utils
t_point **create_map(size_t n_rows, size_t n_cols);
void free_map(t_point **map, size_t n_rows);
size_t count_lines(int fd);
void get_grid_size(int fd, size_t *ptr_rows, size_t *ptr_cols);

// Parse File
t_point **parse_file(int fd, size_t n_rows, size_t n_cols);

// extra 
void free_ft_split(char **str);


#endif