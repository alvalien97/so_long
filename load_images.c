/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:49:21 by alvalien          #+#    #+#             */
/*   Updated: 2025/04/28 10:49:24 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		write(2, "Error\nFailed to load image: ", 29);
		write(2, path, strlen(path));
		write(2, "\n", 1);
		exit(1);
	}
	return (img);
}

void	load_images(t_game *game)
{
	game->img_wall = load_image(game->mlx, "pictures/wall.xpm");
	game->img_floor = load_image(game->mlx, "pictures/floor.xpm");
	game->img_player = load_image(game->mlx, "pictures/player.xpm");
	game->img_exit = load_image(game->mlx, "pictures/exit.xpm");
	game->img_collectable = load_image(game->mlx, "pictures/collectible.xpm");
}
