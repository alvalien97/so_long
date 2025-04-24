#include "./so_long.h"

void    load_images(t_game *game)
{
    int width;
    int height;

    game->images[0] = mlx_xpm_file_to_image(game->mlx, "pictures/wall.xpm", &width, &height);
    game->images[1] = mlx_xpm_file_to_image(game->mlx, "pictures/space.xpm", &width, &height);
    game->images[2] = mlx_xpm_file_to_image(game->mlx, "pictures/player.xpm", &width, &height);
    game->images[3] = mlx_xpm_file_to_image(game->mlx, "pictures/exit.xpm", &width, &height);
    game->images[4] = mlx_xpm_file_to_image(game->mlx, "pictures/collectible.xpm", &width, &height);
}

char	**load_map(char *file, t_game *game)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;
	int		j;

	fd = open(file, O_RDONLY);
    if (fd < 0) {
        printf("Error opening map file: %s\n", strerror(errno));
        return NULL;
    }

    map = malloc(sizeof(char *) * 1000);
    if (!map) {
        printf("Error allocating memory for map\n");
        return NULL;
    }

    i = 0;
    j = 0;
    while ((line = get_next_line(fd))) {
        map[i] = line;
        j++;
        i++;
    }
    map[i] = NULL;
    game->map_width = i;
    game->map_height = j;

    close(fd);
    return map;
}

/*void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->images[0], j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->images[1], j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->images[2], j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->images[3], j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->images[4], j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}*/

void draw_map(t_game *game)
{
    int i, j;

    if (!game || !game->mlx || !game->win) {
        fprintf(stderr, "Error: Invalid mlx or window pointer.\n");
        return;
    }

    // Verificar que las imágenes se hayan cargado correctamente
    for (int idx = 0; idx < 5; ++idx) {
        if (!game->images[idx]) {
            fprintf(stderr, "Error: Image %d not loaded.\n", idx);
            return;
        }
    }

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->images[0], j * TILE_SIZE, i * TILE_SIZE);
            else if (game->map[i][j] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->images[1], j * TILE_SIZE, i * TILE_SIZE);
            else if (game->map[i][j] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->images[2], j * TILE_SIZE, i * TILE_SIZE);
            else if (game->map[i][j] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->images[3], j * TILE_SIZE, i * TILE_SIZE);
            else if (game->map[i][j] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->images[4], j * TILE_SIZE, i * TILE_SIZE);
            j++;
        }
        i++;
    }
}

