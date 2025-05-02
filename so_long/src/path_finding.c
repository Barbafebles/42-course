/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:57:57 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/01 21:46:26 by bfebles-         ###   ########.fr       */
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

// Función de flood fill para validar caminos en el mapa
// Función de flood fill para validar caminos en el mapa
void flood_fill(t_map_info *map_info, int y, int x)
{
    // Verificar límites y obstáculos
    if (y < 0 || x < 0 || y >= map_info->height || x >= map_info->width
        || map_info->map[y][x] == '1' || map_info->map[y][x] == 'F')
        return;
    
    // Marcar la casilla como visitada
    map_info->map[y][x] = 'F';
    
    // Explorar en las cuatro direcciones
    flood_fill(map_info, y + 1, x);  // Abajo
    flood_fill(map_info, y - 1, x);  // Arriba
    flood_fill(map_info, y, x + 1);  // Derecha
    flood_fill(map_info, y, x - 1);  // Izquierda
}

// Ejecutar flood fill con la estructura t_map_info
// Ejecutar flood fill con la estructura t_map_info
void execute_flood_fill(t_path *path, t_map *map)
{
    t_map_info map_info;

    map_info.map = path->temp_map;
    map_info.height = map->height;
    map_info.width = map->width;
    
    // Asegurarse de que las coordenadas se pasen correctamente
    flood_fill(&map_info, path->player_x, path->player_y);
}