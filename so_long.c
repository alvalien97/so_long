#include "./so_long.h"

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
    t_game g_game;
    
    load_images(&g_game);

	g_game.mlx = mlx_init();
    if (!g_game.mlx) {
        printf("Error initializing mlx\n");
        return 1;
    }

    g_game.map = load_map("algo.ber", &g_game);
    if (!g_game.map) {
        printf("Error loading map\n");
        return 1;
    }

    g_game.win = mlx_new_window(g_game.mlx, g_game.map_width * TILE_SIZE, g_game.map_height * TILE_SIZE, "so_long");
    if (!g_game.win) {
        printf("Error creating window\n");
        return 1;
    }
    draw_map(&g_game);
    mlx_hook(g_game.win, 17, 0, close_window, NULL);
    mlx_hook(g_game.win, 2, 1L << 0, key_hook, NULL);
	mlx_loop(g_game.mlx);
    return (0);
}
