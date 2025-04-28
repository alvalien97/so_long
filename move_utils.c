#include "so_long.h"

int is_valid_move(char tile)
{
    if (tile == 1)
        return (0);
    return (1);
}

void    update_position(t_game *game, int new_x,int new_y)
{
    char    tile;

    tile = game->map[new_y][new_x];
    if (tile == 'c')
        game->collected++;
    if (tile == 'E' && game->collected != game->collectables)
        return ;
    if (tile == 'E')
    {
        write(1, "You win\n", 9);
        exit(0);
    }
    game->map[game->player_y][game->player_x] = '0';
    game->player_x = new_x;
    game->player_y = new_y;
    game->map[new_y][new_x] = 'P';
    game->moves++;
    print_moves(game->moves);
}

void    print_moves(int moves)
{
    char    buffer[12];
    int     i;
    int     n;

    n = moves;
    i = 10;
    buffer[11] = '\n';
    while (n > 0)
    {
        buffer[i] = (n % 10) + '0';
        n = n / 10;
        i--;
    }
    write(1, "Move: ", 6);
    write(1, &buffer[i + 1], 10 - i);
}
