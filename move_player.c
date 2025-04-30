/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:49:56 by alvalien          #+#    #+#             */
/*   Updated: 2025/04/28 10:49:58 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *g)
{
	int	new_y;
	int	new_x;

	new_y = g->player_y - 1;
	new_x = g->player_x;
	if (is_valid_move(g->map[new_y][new_x]))
		update_position(g, new_x, new_y);
}

void	move_down(t_game *g)
{
	int	new_y;
	int	new_x;

	new_y = g->player_y + 1;
	new_x = g->player_x;
	if (is_valid_move(g->map[new_y][new_x]))
		update_position(g, new_x, new_y);
}

void	move_left(t_game *g)
{
	int	new_y;
	int	new_x;

	new_y = g->player_y;
	new_x = g->player_x - 1;
	if (is_valid_move(g->map[new_y][new_x]))
		update_position(g, new_x, new_y);
}

void	move_right(t_game *g)
{
	int	new_y;
	int	new_x;

	new_y = g->player_y;
	new_x = g->player_x + 1;
	if (is_valid_move(g->map[new_y][new_x]))
		update_position(g, new_x, new_y);
}

void	handle_input(char key, t_game *g)
{
	if (key == 'w')
		move_up(g);
	else if (key == 's')
		move_down(g);
	else if (key == 'a')
		move_left(g);
	else if (key == 'd')
		move_right(g);
}
