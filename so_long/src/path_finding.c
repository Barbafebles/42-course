/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:57:57 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/02 17:35:59 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**copy_map(t_map *map)
{
	char	**copy;
	size_t	i;

	copy = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < (size_t)map->height)
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy[i])
		{
			i--;
			while (i != (size_t)-1)
			{
				free(copy[i]);
				i--;
			}
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(t_map_info *map_info, int y, int x)
{
	if (y < 0 || x < 0 || y >= map_info->height || x >= map_info->width
		|| map_info->map[y][x] == '1' || map_info->map[y][x] == 'F')
		return ;
	map_info->map[y][x] = 'F';
	flood_fill(map_info, y + 1, x);
	flood_fill(map_info, y - 1, x);
	flood_fill(map_info, y, x + 1);
	flood_fill(map_info, y, x - 1);
}

void	execute_flood_fill(t_path *path, t_map *map)
{
	t_map_info	map_info;

	map_info.map = path->temp_map;
	map_info.height = map->height;
	map_info.width = map->width;
	flood_fill(&map_info, path->player_x, path->player_y);
}
