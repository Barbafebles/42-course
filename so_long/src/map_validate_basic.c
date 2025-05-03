/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_basic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:57:27 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/03 11:43:53 by bfebles-         ###   ########.fr       */
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
				ft_error("Carácter inválido en el mapa");
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
	printf("Collectables: %d\n", map->collectable);
}

void	check_map_char(t_map *map)
{
	if (map->player == 0)
		ft_error("No hay jugador en el mapa");
	if (map->player > 1)
		ft_error("Hay más de un jugador en el mapa");
	if (map->exit == 0)
		ft_error("No hay salida en el mapa");
	if (map->exit > 1)
		ft_error("Hay más de una salida en el mapa");
	if (map->collectable < 1)
		ft_error("No hay coleccionables en el mapa");
}

void	check_wall(t_map *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < map->width)
	{
		if (map->grid[0][x] != '1' || map->grid[map->height - 1][x] != '1')
			ft_error("Error pared");
		x++;
	}
	y = 0;
	while (y < map->height)
	{
		if (map->grid[y][0] != '1' || map->grid[y][map->width - 1] != '1')
			ft_error("Error pared");
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
			ft_error("El mapa no es rectangular");
		i++;
	}
}
