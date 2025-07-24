/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:16:50 by alvalien          #+#    #+#             */
/*   Updated: 2024/10/17 17:16:54 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_calloc(i + 2, sizeof(char));
	else
		line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_free_join(char *gnl_buf, char *buf)
{
	char	*join;

	if (!gnl_buf)
		return (ft_strdup(buf));
	join = ft_strjoin(gnl_buf, buf);
	free(gnl_buf);
	return (join);
}

char	*read_file(int fd, char *gnl_buf)
{
	char	*buffer;
	int		reading_bytes;

	if (!gnl_buf)
		gnl_buf = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	reading_bytes = 1;
	while (reading_bytes > 0)
	{
		reading_bytes = read(fd, buffer, BUFFER_SIZE);
		if (reading_bytes < 0)
		{
			free(buffer);
			free(gnl_buf);
			return (NULL);
		}
		buffer[reading_bytes] = '\0';
		gnl_buf = ft_free_join(gnl_buf, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (gnl_buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*row;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
	{
		if (fd <= 0 && fd < FOPEN_MAX && buffer[fd])
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (NULL);
	}
	if (!buffer[fd])
		buffer[fd] = ft_calloc(1, sizeof(char));
	if (!buffer[fd])
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	row = ft_line(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (row);
}

/*int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);
	char *line;
	char *line2;
	char *line3;
	if (fd < 0 || fd2 < 0 || fd3 < 0) {
		perror("Error al abrir uno de los archivos");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);

		if (!line && !line2 && !line3)
			break;

		if (line) {
			printf("%s", line);
			free(line);
		}
		if (line2) {
			printf("%s", line2);
			free(line2);
		}
		if (line3) {
			printf("%s", line3);
			free(line3);
		}
	}
	
	close(fd);
	close(fd2);
	close(fd3);
	int n = 0;

	while (n < 15)
	{
		line = get_next_line(fd);
		printf("linea[%d]: %s\n",n , line);
		free(line);
		n++;
	}
	return (0);
}*/