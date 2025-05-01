/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:52:22 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/01 19:16:21 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// verifica si los caracteres son validos para el mapa
void	check_char(int i)
{
	if (!(ft_strchr("01PEC", i)))
		ft_error("caracter no existe\n");
}

// Verifica si el mapa existe y que este en el formato adecuado. 
void	check_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("No se puede abrir el archivo");
	close(fd);
}

// Verifica si el archivo del mapa existe y se puede abrir
// Si no se puede abrir, muestra un error
void	check_empty_map(t_map *map)
{
	if (map->height == 0 || map->width == 0)
		ft_error("El mapa está vacío");
}

// Verifica si el archivo tiene la extensión correcta (.ber)
// Si la extensión no es .ber, muestra un error
void	check_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(&filename[len - 4], ".ber", 4) != 0)
	{
		ft_error("la extension del mapa no es la correcta.");
	}
}


// Busca la posición del jugador (P) en el mapa
// Guarda las coordenadas en los punteros p_x y p_y
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
