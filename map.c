#include "so_long.h"

void    *load_image(void *mlx, char *file_path)
{
    int width, height;
    return mlx_xpm_file_to_image(mlx, file_path, &width, &height);
}

int	**load_map(char *file)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = NULL;
	map = malloc(sizeof(char *) * 1000);
	if (!map)
		return (NULL);
    i = 0;
	while ((line = get_next_line(fd))) //guardo linea a linea lo que hay en el .ber
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	draw_map(void *mlx, void *win, char **map, t_images *imgs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, images[0], x * 64, y * 64);
			else if (map[i][j] == '0')
                mlx_put_image_to_window(mlx, win, images[1], x *64, y * 64);
			else if (map[i][j] == 'P')
                mlx_put_image_to_window(mlx, win, images[2], x *64, y * 64);
			else if (map[i][j] == 'E')
                mlx_put_image_to_window(mlx, win, images[3], x *64, y * 64);
			else if (map[i][j] == 'C')
                mlx_put_image_to_window(mlx, win, images[4], x *64, y * 64);
			mlx_put_image_to_window(mlx, win, images[0], j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
		j = 0;
	}
}
