#include "so_long.h"

static int  is_rectangle(char **map, int height, int width)
{
    int i;

    i = 0;
    while (i < height)
    {
        if (ft_strlen(map[i] - 1 != width))
            return (0);
        i++;
    }
    return (1);
}

static int  check_walls(char **map, int width, int height)
{
    int i;

    i = 0;
    while (i < width)
    {
        if (map[0][i] != '1' || map[height - 1] != '1')
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

int check_tile(char c, int *p, int *e, int *c_count)
{
    if (c == 'P')
    {
        (*p)++;
        return(1);
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
    else if (c == '0' || c == '1' || c == '\n')
        return (1);
    return (0);
}

int check_contents(t_game *game)
{
    int y;
    int x;
    int p;
    int e;
    int c;

    y = 0;
    p = 0;
    e = 0;
    c = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (!check_tile(game->map[y][x], &p, &e, &c))
                return (0);
            if (game->map[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
            }
            x++;
        }
        y++;
    }
    if (p != 1 || e != 1 || c < 1)
        return (0);
    game->collectables = c;
    return (1);
}

int validate_map(t_game *game)
{
    if (!is_rectangle(game->map, game->height, game->width))
        return (0);
    if (!check_walls(game->map, game->width, game->height))
        return (0);
    if (!check_contents(game))
        return (0);
    return (1);
}
