/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:24:09 by alvalien          #+#    #+#             */
/*   Updated: 2025/04/29 10:24:11 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TILE_SIZE 96
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectables;
	int		collected;
	int		moves;
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectable;
}			t_game;

int			check_tile(char c, int *p, int *e, int *c_count);
int			help_contents(t_game *game, int *p, int *e, int *c);
int			check_contents(t_game *game);
int			is_rectangle(char **map, int height, int width);
int			check_walls(char **map, int width, int height);
int			validate_map(t_game *game);
void		*load_image(void *mlx, char *path);
void		load_images(t_game *game);
void		draw_tile(t_game *g, void *img, int x, int y);
void		draw_map(t_game *g);
int			handle_key(int keycode, t_game *g);
int			close_window(t_game *g);
void		move_up(t_game *g);
void		move_down(t_game *g);
void		move_left(t_game *g);
void		move_right(t_game *g);
void		handle_input(char key, t_game *g);
int			is_valid_move(char tile);
void		update_position(t_game *game, int new_x, int new_y);
void		print_moves(int moves);
char		**read_map(const char *filename, t_game *game);
void		free_map(char **map);
int			validate_coins(t_game *game, int i, int j);
int			map_solvable(t_game *game);
#endif
