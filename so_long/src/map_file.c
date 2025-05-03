/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:58:17 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/02 22:07:48 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*append_char(char *line, size_t len, char c)
{
	char	*tmp;

	tmp = ft_calloc(len + 2, 1);
	if (!tmp)
		ft_error("Malloc failed in append_char");
	if (len > 0)
		ft_memcpy(tmp, line, len);
	tmp[len] = c;
	free(line);
	return (tmp);
}

int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error al abrir el archivo del mapa");
	return (fd);
}

char	*read_line(int fd)
{
	char	c;
	ssize_t	ret;
	size_t	len;
	char	*line;

	line = ft_calloc(1, 1);
	len = 0;
	if (!line)
		ft_error("Malloc failed in read_line");
	ret = read(fd, &c, 1);
	while (ret > 0 && c != '\n')
	{
		line = append_char(line, len, c);
		len++;
		ret = read(fd, &c, 1);
	}
	if (ret <= 0 && len == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

void	free_map(t_map *map)
{
	size_t	i;

	if (!map->grid)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}
