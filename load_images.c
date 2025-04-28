#include "so_long.h"

void	*load_image(void *mlx, char *path)
{
	void	*img;
	int		w;
	int		h;

	w = TILE_SIZE;
	h = TILE_SIZE;
	img = mlx_xpm_file_to_image(mlx, path, &w, &h);
	if (!img)
	{
		write(2, "Error\nImage load failed\n", 25);
		exit(1);
	}
	return (img);
}

void	load_images(t_game *game)
{
	game->img_wall = load_image(game->mlx, "assets/wall.xpm");
	game->img_floor = load_image(game->mlx, "assets/floor.xpm");
	game->img_player = load_image(game->mlx, "assets/player.xpm");
	game->img_exit = load_image(game->mlx, "assets/exit.xpm");
	game->img_collectable = load_image(game->mlx, "assets/collectable.xpm");
}
