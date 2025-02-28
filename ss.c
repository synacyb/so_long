#include "minilibx-linux/mlx.h"
#define TILE_SIZE 64  // Size of each wall tile
#define WALL_WIDTH 4   // Number of tiles horizontally
#define WALL_HEIGHT 3  // Number of tiles vertically

int main() {
    void *mlx;
    void *win;
    void *img;
    int img_width, img_height;

    // Initialize MiniLibX
    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "Game Window");

    // Load the image (must be in XPM format)
    img = mlx_xpm_file_to_image(mlx, "wall/pwall.xpm", &img_width, &img_height);
    // if (!img) {
    //     write(2, "Error: Failed to load image\n", 28);
    //     return 1;
    // }

    // Set the exact position (x, y) where you want to put the image
    int x_position = 1;
    int y_position = 1;

    // Put the image to the window at (x_position, y_position)
    mlx_put_image_to_window(mlx, win, img, x_position, y_position);
    mlx_put_image_to_window(mlx, win, img, x_position + 15, y_position + 115);
    // Start MiniLibX event loop
    mlx_loop(mlx);

    return 0;
}

