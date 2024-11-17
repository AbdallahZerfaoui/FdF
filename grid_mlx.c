#include "includes/mlx.h"
#include <stdlib.h>

#define WIN_WIDTH 500
#define WIN_HEIGHT 500
#define PIXEL_SIZE 2  // Size of each pixel in the grid
#define GRID_ROWS 10   // Number of rows in the grid
#define GRID_COLS 10   // Number of columns in the grid
#define offset 50
#define step 25
#define RED 0xFF0000   // Color code for red (hex value)

typedef struct s_data {
    void    *mlx_ptr;   // MLX instance pointer
    void    *win_ptr;   // Window pointer
} t_data;

// Function to draw a grid of red pixels
void draw_grid(t_data *data)
{
    int row, col;
    int x, y;

    for (row = 0; row < GRID_ROWS; row++) {
        for (col = 0; col < GRID_COLS; col++) {
            x = offset + col * step;  // Calculate x position
            y = offset + row * step;  // Calculate y position
            for (int i = 0; i < PIXEL_SIZE; i++) {
                for (int j = 0; j < PIXEL_SIZE; j++) {
                    mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + i, y + j, RED);
                }
            }
        }
    }
}

int main(void)
{
    t_data data;

    // Initialize MiniLibX and create a new window
    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Red Grid");

    // Draw the grid of red pixels
    draw_grid(&data);

    // Enter the MiniLibX event loop
    mlx_loop(data.mlx_ptr);

    return 0;
}
