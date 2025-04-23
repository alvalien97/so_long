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

char **map;
int map_width, map_height;
void *mlx;
void *win;
void *img_wall;
void *img_space;
void *img_player;
void *img_exit;
void *img_collectible;

int close_window(void *param);
int key_hook(int keycode, void *param);
void    *load_image(void *mlx, char *file_path);
int	**load_map(char *file);
void    load_images();

#endif