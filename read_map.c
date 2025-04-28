#include "so_long.h"

static int  get_height(const char *filename)
{
    int fd;
    int height;
    char *line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (0);
    height = 0;
    while (line = get_next_line(fd))
    {
        height++;
        free(line);
    }
    close(fd);
    return (height);
}

char **read_map(const char *filename, t_game *game)
{
    int fd;
    char **map;
    char *line;
    int i;

    game->height = get_height(filename);
    if (game->height < 4)
        return (NULL);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);
    map = malloc(sizeof(char *) * (game->height + 1));
    if (!map)
        return(NULL);
    i = 0;
    while (line = get_next_line(fd))
        map[i++] = line;
    map[i] = NULL;
    game->width = ft_strlen(map[0]) - 1;
    close(fd);
    return (map);
}

void    free_map(char **map)
{
    int i;

    i = 0;
    while(map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}