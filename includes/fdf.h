#ifndef FDF_H
# define FDF_H

#define WIN_WIDTH 1000
#define WIN_HEIGHT 1000
#define PIXEL_SIZE 2
#define OFFSET 50
#define RED 0xFF0000
#define WHITE 0xFFFFFF
#define BLUE 0x0000FF

#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

#include "libft.h"
#include "get_next_line.h"
#include "libftprintf.h"
#include "mlx.h"
// #include "../minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <math.h>


typedef struct s_point
{
    int x;
    int y;
    int z;
} t_point;

typedef struct s_2d_point
{
    int iso_x;
    int iso_y;
} t_2d_point;

typedef struct s_data {
    void    *mlx_ptr;
    void    *win_ptr;
    t_point **map;      // Map containing your 3D points
    size_t  n_rows;     // Number of rows in the map
    size_t  n_cols;     // Number of columns in the map
	int		zoom;
	int 	x_offset;
	int 	y_offset;
} t_data;

// typedef struct s_fdf
// {
// 	void *mlx_ptr;
// 	void *win_ptr;
// 	t_point **map;
// 	size_t n_rows;
// 	size_t n_cols;
// 	int zoom;
// 	int color;
// 	int z_zoom;
// 	int x_offset;
// 	int y_offset;
// } t_fdf;

// Utils
t_point **create_map(size_t n_rows, size_t n_cols);
void free_map(t_point **map, size_t n_rows);
size_t count_lines(int fd);
void get_grid_size(int fd, size_t *ptr_rows, size_t *ptr_cols);
int min_map(t_point **map, size_t n_rows, size_t n_cols);
int max_map(t_point **map, size_t n_rows, size_t n_cols);

// Parse File
t_point **parse_file(int fd, size_t n_rows, size_t n_cols);

// extra 
void free_ft_split(char **str);

// Render
t_2d_point isometric_projection(t_point point, int zoom, int x_offset, int y_offset);
void draw_pixel(t_data *data, int x, int y, int color);
int get_color(int z, t_data *data);
void render_map(t_data *data);


#endif