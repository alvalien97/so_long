#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

# define TILE_SIZE 32

typedef struct s_game
{
    char	**map;
	int		width;
	int		height;
	int		player_x;
    int     player_y;
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
} t_game;

//recorrer el mapa y validarlo
char    **read_map(const char *filename, t_game *game);
int     validate_map(t_game *game);

//utils
void    free_map(char **map);


int close_window(void *param);
int key_hook(int keycode, void *param);
void    load_images(t_game *game);
char	**load_map(char *file, t_game *game);
void	draw_map(t_game *game);

#endif