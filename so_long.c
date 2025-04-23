#include "so_long.h"

int close_window(void *param)
{
    (void)param;
    exit (0);
}

int key_hook(int keycode, void *param)
{
    (void)param;
    if (keycode == 65307)
        exit (0);
    return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;
    void    *images[5];
    char    **map;

    
	mlx = mlx_init();
	win = mlx_new_window(mlx, 2000, 1600, "so_long");
    images[0] = load_image(mlx, "walls.xpm");
    images[1] = load_image(mlx, "background.xpm");
    images[2] = load_image(mlx, "person.xpm");
    images[3] = load_image(mlx, "end.xpm");
    images[4] = load_image(mlx, "collectable.xpm");
    map = load_map("algo.ber");
    draw_map(mlx, win, map, map, floor_img);
    mlx_hook(win, 17, 0, close_window, NULL);
    mlx_hook(win, 2, 1L << 0, key_hook, NULL);
	mlx_loop(mlx);
	return (0);
}
