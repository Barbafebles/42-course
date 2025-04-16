/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:56:50 by bfebles-          #+#    #+#             */
/*   Updated: 2025/04/16 16:41:24 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	load_map_lines(int fd, t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		map->grid[i] = read_line(fd);
		if (!map->grid[i])
		{
			while (i > 0)
				free(map->grid[--i]);
			free(map->grid);
			return (0);
		}
		i++;
	}
	map->grid[i] = NULL;
	return (1);
}

int	init_map(t_map *map, char *filename)
{
	map->height = count_lines(filename);
	if (map->height == 0)
		return (0);
	map->grid = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (0);
	return (1);
}

int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error al abrir el archivo del mapa");
	return (fd);
}

int	load_map(char *filename, t_map *map)
{
	int	fd;

	fd = open_map_file(filename);
	if (fd < 0)
		return (0);
	if (!init_map(map, filename))
	{
		close(fd);
		return (0);
	}
	if (!load_map_lines(fd, map))
	{
		close(fd);
		return (0);
	}
	if (map->height > 0)
		map->width = ft_strlen(map->grid[0]);
	else
		map->width = 0;
	close(fd);
	return (1);
}

/*------------- identificado -----------------------*/
size_t	count_lines(char *filename)
{
	int		fd;
	char	buffer[4096];
	ssize_t	bytes_read;
	size_t	count;
	ssize_t	i;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
				count++;
			i++;
		}
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	if (bytes_read > 0 && buffer[bytes_read - 1] != '\n')
		count++;
	close(fd);
	return (count);
}

char	*read_line(int fd)
{
	char	buffer[4096];
	char	*line;
	ssize_t	bytes_read;
	ssize_t	i;
	size_t	start;

	line = NULL;
	start = 0;
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read <= 0)
		return (NULL);
	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			line = ft_strdup(&buffer[start]);
			lseek(fd, -(bytes_read - i - 1), SEEK_CUR);
			return (line);
		}
		i++;
	}
	line = ft_strdup(buffer);
	return (line);
}

void	free_map(t_map *map)
{
	size_t	i;

	if (map->grid)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
}
