/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:56:50 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/03 11:14:54 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	load_map_lines(int fd, t_map *map)
{
	size_t	i;
	char	*line;

	i = 0;
	while (i < map->height)
	{
		line = read_line(fd);
		if (!line)
		{
			while (i-- > 0)
				free(map->grid[i]);
			free(map->grid);
			return (0);
		}
		map->grid[i++] = line;
	}
	map->grid[i] = NULL;
	return (1);
}

int	init_map(t_map *map, char *filename)
{
	map->height = count_lines(filename);
	map->collectable = 0;
	if (map->height == 0)
		return (0);
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	return (map->grid != NULL);
}

int	load_map(char *filename, t_map *map)
{
	int	fd;

	fd = open_map_file(filename);
	if (fd < 0 || !init_map(map, filename))
		return (close(fd), 0);
	if (!load_map_lines(fd, map))
		return (close(fd), 0);
	if (map->height > 0)
		map->width = ft_strlen(map->grid[0]);
	else
		map->width = 0;
	close(fd);
	return (1);
}
