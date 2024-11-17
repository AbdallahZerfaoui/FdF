// test_mlx.c
#include "minilibx-linux/mlx.h"

int main(void)
{
    void *mlx;
    void *window;

    // Initialize the connection to the graphical server
    mlx = mlx_init();
    if (!mlx)
        return (1);

    // Create a new window
    window = mlx_new_window(mlx, 800, 600, "MiniLibX Test Window");
    if (!window)
        return (1);

    // Start the MiniLibX event loop
    mlx_loop(mlx);

    return (0);
}