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
    char **map;
    int map_width;
    int map_height;
    void *mlx;
    void *win;
    void *images[5];
} t_game;

int close_window(void *param);
int key_hook(int keycode, void *param);
void    load_images(t_game *game);
char	**load_map(char *file, t_game *game);
void	draw_map(t_game *game);

#endif