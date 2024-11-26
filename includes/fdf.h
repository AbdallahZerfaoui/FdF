/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:50:44 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/26 17:21:03 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define PIXEL_SIZE 2
# define GRID_ROWS 10
# define GRID_COLS 10
# define OFFSET 50
# define STEP 25
# define ZOOM 1
# define STEP_Z 2
# define RED 0xFF0000
# define WHITE 0xFFFFFF
# define BLUE 0x0000FF
# define ESC_KEY 53

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
}			t_point;

typedef struct s_2d_point
{
	int		iso_x;
	int		iso_y;
	size_t	i;
	size_t	j;
}			t_2d_point;

typedef struct s_line
{
	int		delta_x;
	int		delta_y;
	int		sign_x;
	int		sign_y;
	int		error;
	int		error2;
}			t_line;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_point	**map;
	int		**colors_map;
	size_t	n_rows;
	size_t	n_cols;
	int		zoom;
	int		x_offset;
	int		y_offset;
}			t_data;

typedef struct s_map_params
{
	t_point	**map;
	int		**colors_map;
	size_t	zoom_coeff;
	size_t	step_x;
	size_t	step_y;
	size_t	step_z;
	size_t	n_rows;
	size_t	n_cols;
	char	**values;
}			t_map_params;

typedef struct s_rgb
{
	int		red;
	int		green;
	int		blue;
}			t_rgb;

// Utils
t_point		**create_map(size_t n_rows, size_t n_cols);
int			**create_colors_map(size_t n_rows, size_t n_cols);
void		free_map(void **map, size_t n_rows);
void		free_all_maps(t_data *data, t_map_params *params);
size_t		count_lines(int fd);
void		get_grid_size(int fd, size_t *ptr_rows, size_t *ptr_cols);
int			min_map(t_point **map, size_t n_rows, size_t n_cols);
int			max_map(t_point **map, size_t n_rows, size_t n_cols);

// Parse File
void		parse_file(int fd, t_map_params *params);

// extra
void		free_ft_split(char **str);

// Render
t_2d_point	isometric_projection(t_point point, int zoom, int x_offset,
				int y_offset);
void		draw_pixel(t_data *data, int x, int y, int color);
int			get_color(int z, t_map_params *data);
void		render_map(t_data *data);

// Draw
void		draw_pixel(t_data *data, int x, int y, int color);
void		draw_line(t_data *data, t_2d_point p1, t_2d_point p2, int color);
t_2d_point	draw_elem_from_data(t_data *data, int i, int j, int color);
void		draw_horizontal_line(t_data *data, t_2d_point p1, int color);
void		draw_vertical_line(t_data *data, t_2d_point p1, int color);

// Events
int			handle_keypress(int keysym, t_data *data);
int			handle_destroy(t_data *data);

// Maths
size_t		ft_min(size_t a, size_t b);
size_t		ft_max(size_t a, size_t b);

// Errors
void		display_error(void);
void		handle_inputs(int argc);
#endif