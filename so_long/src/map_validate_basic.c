/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_basic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:57:27 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/06 17:48:29 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	count_elements(t_map *map)
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
				map->player++;
			else if (map->grid[x][y] == 'E')
				map->exit++;
			else if (map->grid[x][y] == 'C')
				map->collectable++;
			else if (map->grid[x][y] != '0' && map->grid[x][y] != '1')
				ft_error("Invalid character on the map");
			y++;
		}
		x++;
	}
}

void	check_map(t_map *map)
{
	map->player = 0;
	map->collectable = 0;
	map->exit = 0;
	count_elements(map);
	ft_printf("Collectables: %d\n", map->collectable);
}

void	check_map_char(t_map *map)
{
	if (map->player == 0)
		ft_error("No player on the map");
	if (map->player > 1)
		ft_error("There is more than one player on the map");
	if (map->exit == 0)
		ft_error("No exit on the map");
	if (map->exit > 1)
		ft_error("There is more than one exit on the map");
	if (map->collectable < 1)
		ft_error("There are no collectibles on the map");
}

void	check_wall(t_map *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < map->width)
	{
		if (map->grid[0][x] != '1' || map->grid[map->height - 1][x] != '1')
			ft_error("Wall error");
		x++;
	}
	y = 0;
	while (y < map->height)
	{
		if (map->grid[y][0] != '1' || map->grid[y][map->width - 1] != '1')
			ft_error("Wall error");
		y++;
	}
}

void	check_recta(t_map *map)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(map->grid[0]);
	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->grid[i]) != len)
			ft_error("The map is not rectangular");
		i++;
	}
}
