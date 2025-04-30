/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_coins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:02:41 by alvalien          #+#    #+#             */
/*   Updated: 2025/04/29 17:02:44 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_coins(t_game *game, int i, int j)
{
	if (game->map[i][j + 1] == '1' && game->map[i][j - 1] == '1')
	{
		if (game->map[i - 1][j] == '1' && game->map[i + 1][j] == '1')
		{
			perror("Error, meta imposible");
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}

static void	flood_fill(t_game *game, char **map, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(game, map, x + 1, y);
	flood_fill(game, map, x - 1, y);
	flood_fill(game, map, x, y + 1);
	flood_fill(game, map, x, y - 1);
}

void	map_auxiliar(t_game *game, char **map_copy, int *collectables_all,
		int *exit_found)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C' && map_copy[i][j] == 'V')
				(*collectables_all)++;
			if (game->map[i][j] == 'E' && map_copy[i][j] == 'V')
				*exit_found = 1;
			j++;
		}
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

int	map_solvable(t_game *game)
{
	char	**map_copy;
	int		i;
	int		collectables_all;
	int		exit_found;

	collectables_all = 0;
	exit_found = 0;
	map_copy = malloc(sizeof(char *) * (game->height + 1));
	if (!map_copy)
		return (0);
	i = 0;
	while (i < game->height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		i++;
	}
	map_copy[i] = NULL;
	flood_fill(game, map_copy, game->player_x, game->player_y);
	map_auxiliar(game, map_copy, &collectables_all, &exit_found);
	if (collectables_all != game->collectables || !exit_found)
		return (0);
	return (1);
}
