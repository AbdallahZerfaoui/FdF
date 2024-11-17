/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:42:59 by azerfaou          #+#    #+#             */
/*   Updated: 2024/11/17 18:51:06 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "includes/mlx.h"
#include "includes/fdf.h"
#include <stdlib.h>

// #define WIN_WIDTH 500
// #define WIN_HEIGHT 500
// #define PIXEL_SIZE 2 // Size of each pixel in the grid
// #define GRID_ROWS 10 // Number of rows in the grid
// #define GRID_COLS 10 // Number of columns in the grid
// #define OFFSET 50
// #define STEP 25
// #define RED 0xFF0000 // Color code for red (hex value)

// Function to draw a grid of red pixels
void	draw_grid(t_data *data)
{
	int	row;
	int	col;
	int	x;
	int	y;

	row = 0;
	col = 0;
	for (row = 0; row < GRID_ROWS; row++)
	{
		for (col = 0; col < GRID_COLS; col++)
		{
			x = OFFSET + col * STEP; // Calculate x position
			y = OFFSET + row * STEP; // Calculate y position
			for (int i = 0; i < PIXEL_SIZE; i++)
			{
				for (int j = 0; j < PIXEL_SIZE; j++)
				{
					mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + i, y + j,
						RED);
				}
			}
		}
	}
}

int	main(void)
{
	t_data	data;

	// Initialize MiniLibX and create a new window
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"Red Grid");
	// Draw the grid of red pixels
	draw_grid(&data);
	// Enter the MiniLibX event loop
	mlx_loop(data.mlx_ptr);
	return (0);
}
