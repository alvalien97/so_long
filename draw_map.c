/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:49:10 by alvalien          #+#    #+#             */
/*   Updated: 2025/04/28 10:49:13 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_game *g, void *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img, x * TILE_SIZE, y * TILE_SIZE);
}

void	draw_map(t_game *g)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			tile = g->map[y][x];
			draw_tile(g, g->img_floor, x, y);
			if (tile == '1')
				draw_tile(g, g->img_wall, x, y);
			else if (tile == 'P')
				draw_tile(g, g->img_player, x, y);
			else if (tile == 'C')
				draw_tile(g, g->img_collectable, x, y);
			else if (tile == 'E')
				draw_tile(g, g->img_exit, x, y);
			x++;
		}
		y++;
	}
}

int	handle_key(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W)
		move_up(g);
	else if (keycode == KEY_A)
		move_left(g);
	else if (keycode == KEY_S)
		move_down(g);
	else if (keycode == KEY_D)
		move_right(g);
	draw_map(g);
	return (0);
}

int	close_window(t_game *g)
{
	free_map(g->map);
	exit(0);
}

int	validate_map(t_game *game)
{
	if (!is_rectangle(game->map, game->height, game->width))
	{
		write(2, "Error rectangle", 15);
		return (0);
	}
	if (!check_walls(game->map, game->width, game->height))
	{
		write(2, "Error muros", 11);
		return (0);
	}
	if (!check_contents(game))
	{
		write(2, " Content", 8);
		return (0);
	}
	if (!map_solvable(game))
	{
		write(2, "Error map mistake", 17);
		return (0);
	}
	return (1);
}
