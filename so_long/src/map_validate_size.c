/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:45:08 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/06 17:49:29 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_size(t_map *map)
{
	if (!map || !map->grid)
		ft_error("Invalid map");
	if (map->height < 3 || map->width < 3)
		ft_error("The map is too small (minimum 3x3).");
	if (map->height > 50 || map->width > 50)
		ft_error("The map is too large (maximum 50x50).");
	if (map->width * map->height < 9)
		ft_error("The map does not have enough space");
}

void	save_exit_position(t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'E')
			{
				map->exit_x = x;
				map->exit_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
