/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:57:57 by bfebles-          #+#    #+#             */
/*   Updated: 2025/04/02 17:28:55 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Crear una copia del mapa para flood fill
char	**copy_map(t_map *map)
{
	char	**copy;
	size_t	i;

	copy = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

// Función de flood fill para validar caminos en el mapa
void	flood_fill(t_map_info *map_info, int x, int y)
{
	if (x < 0 || y < 0 || x >= map_info->height || y >= map_info->width
		|| map_info->map[x][y] == '1' || map_info->map[x][y] == 'F')
		return ;
	map_info->map[x][y] = 'F';
	flood_fill(map_info, x + 1, y);
	flood_fill(map_info, x - 1, y);
	flood_fill(map_info, x, y + 1);
	flood_fill(map_info, x, y - 1);
}

// Ejecutar flood fill con la estructura t_map_info
void	execute_flood_fill(t_path *path, t_map *map)
{
	t_map_info	map_info;

	map_info.map = path->temp_map;
	map_info.height = map->height;
	map_info.width = map->width;
	flood_fill(&map_info, path->player_x, path->player_y);
}
