/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:47:23 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/03 11:48:25 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**dup_map(t_map *map)
{
	size_t	i;
	char	**dup;

	dup = malloc(sizeof(char *) * map->height);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		dup[i] = ft_strdup(map->grid[i]);
		i++;
	}
	return (dup);
}

static void	find_player_pos(t_map *map, size_t *px, size_t *py)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'P')
			{
				*px = i;
				*py = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static int	check_reachable(char **dup, t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if ((map->grid[i][j] == 'C' || map->grid[i][j] == 'E')
				&& dup[i][j] != 'F')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	free_dup(char **dup, size_t h)
{
	size_t	i;

	i = 0;
	while (i < h)
	{
		free(dup[i]);
		i++;
	}
	free(dup);
}

int	check_path(t_map *map)
{
	char	**dup;
	size_t	px;
	size_t	py;
	int		ok;

	dup = dup_map(map);
	if (!dup)
		return (0);
	find_player_pos(map, &px, &py);
	execute_flood_fill((t_path *)&(t_path){.temp_map = dup, .player_x = px,
		.player_y = py}, map);
	ok = check_reachable(dup, map);
	free_dup(dup, map->height);
	return (ok);
}
