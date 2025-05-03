/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:45:08 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/03 11:45:33 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_size(t_map *map)
{
	if (!map || !map->grid)
		ft_error("Mapa inválido");
	if (map->height < 3 || map->width < 3)
		ft_error("El mapa es demasiado pequeño (mínimo 3x3)");
	if (map->height > 50 || map->width > 50)
		ft_error("El mapa es demasiado grande (máximo 50x50)");
	if (map->width * map->height < 9)
		ft_error("El mapa no tiene suficiente espacio");
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
