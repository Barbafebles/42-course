/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:52:22 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/06 17:43:49 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_char(int i)
{
	if (!(ft_strchr("01PEC", i)))
		ft_error("character does not exist\n");
}

void	check_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Unable to open the file");
	close(fd);
}

void	check_empty_map(t_map *map)
{
	if (map->height == 0 || map->width == 0)
		ft_error("The map is empty");
}

void	check_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(&filename[len - 4], ".ber", 4) != 0)
	{
		ft_error("the map extension is not correct");
	}
}

void	find_player(t_map *map, int *p_x, int *p_y)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			if (map->grid[x][y] == 'P')
			{
				*p_x = (int)x;
				*p_y = (int)y;
				return ;
			}
			y++;
		}
		x++;
	}
}
