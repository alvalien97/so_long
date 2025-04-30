/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:50:43 by alvalien          #+#    #+#             */
/*   Updated: 2025/04/28 10:50:47 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while ((map[i][j]))
			j++;
		if (j != width)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_tile(char c, int *p, int *e, int *c_count)
{
	if (c == 'P')
	{
		(*p)++;
		return (1);
	}
	else if (c == 'E')
	{
		(*e)++;
		return (1);
	}
	else if (c == 'C')
	{
		(*c_count)++;
		return (1);
	}
	else if (c == '0' || c == '1')
		return (1);
	return (0);
}

int	help_contents(t_game *game, int *p, int *e, int *c)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (!check_tile(game->map[y][x], p, e, c))
				return (0);
			else if (game->map[y][x] == 'C' || game->map[y][x] == 'P'
				|| game->map[y][x] == 'E')
				validate_coins(game, y, x);
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_contents(t_game *game)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	help_contents(game, &p, &e, &c);
	if (p != 1 || e != 1 || c < 1)
	{
		write(2, "Error content", 13);
		return (0);
	}
	game->collectables = c;
	return (1);
}
