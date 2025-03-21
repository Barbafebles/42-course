/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:49:34 by bfebles-          #+#    #+#             */
/*   Updated: 2025/03/19 18:58:37 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
0: Representa un espacio vacío en el mapa.
1: Representa una pared en el mapa.
P: Representa la posición inicial del jugador.
E: Representa la salida del mapa.
C: Representa un coleccionable que el jugador debe recoger.
*/
// Cada celdad sea uno de los validos 
void check_char(int i)
{
    if(!(ft_strchr("01PEC", i)))
        ft_error("caracter no existe\n");
}
// recorro toda la matriz y llamo a check_char si encuentra algo que no es 0 y 1 
void check_map(t_map *map)
{
	size_t x;
	size_t y;
	map->player = 0;
	map->collectable = 0;
	map->exit = 0;
	x = 0; 
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			if(map->grid[x][y] == 'P')
				map->player++;
			else if(map->grid[x][y] == 'E')
				map->exit++;
			else if(map->grid[x][y] == 'C')
				map->collectable++;
			else if(map->grid[x][y] != 0 && map->grid[x][y] != '0' && map->grid[x][y] != '\0')
				check_char(map->grid[x][y]);
				y++;
		}
		x++;
	}
}
// chequear que el mapa tiene los limites del mapa 
void check_map_char(t_map *map)
{
    
    if (map->player != 1 || map->exit != 1 || map->collectable < 1)
        ft_error("El contenido del mapa no es valido");
}
// Chequea que las paredes sean 1 (que el mapa este cerrado)
void check_wall(t_map *map)
{
    size_t x;
    size_t y;
    
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
// tamano del mapa 
void	check_recta(t_map *map)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(map->grid[0]);
	while (map->grid[i])
	{
		if (ft_strlen(map->grid[i]) != len)
			ft_error("El mapa no es rectangular");
		i++;
	}
}

// validacion archivo del mapa .ber 
void check_extension(char *filename)
{
	size_t len;
	len = ft_strlen(filename)
	if (len < 4 || ft_strncmp(&filename[len - 4], ".ber", 4) != 0)
		ft_error("la extension del mapa no es la correcta.")
}

// funcion para encontrar el jugador
void find_player(t_map *map, int p_X, int p_y)
{
    int x,
    int y; 
    x = 0;
    while ( x < map->height)
    {
        y = 0; 
        while (y < map->width)
        {
            if (map->grid[x][y] == 'P')
                *p_x = x;
                *p_y = y; 
                return; 
        }
        y++;
    }
    x++;
}

// Copia del mapa con flood fill
char **copy_map(t_map *map)
{
    
}













