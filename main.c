#include "so_long.h"

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	game.map = read_map(argv[1], &game);
	if (!game.map || !validate_map(&game))
		return (1);
	game.collected = 0;
	game.moves = 0;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx,
		game.width * TILE_SIZE, game.height * TILE_SIZE, "so_long");
	load_images(&game);
	draw_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
