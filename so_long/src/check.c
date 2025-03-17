#include "so_long.h"

/*
0: Representa un espacio vacío en el mapa.
1: Representa una pared en el mapa.
P: Representa la posición inicial del jugador.
E: Representa la salida del mapa.
C: Representa un coleccionable que el jugador debe recoger.
*/

void check_invalid_char(int i)
{
    if(!(ft_strchr("01PEC", c)))
        ft_error("caracter no existe\n")
}

void	check_map(t_map *map)
{
	size_t	x;
	size_t	y;
	char	cell;

	map->player = 0;
	map->collectable = 0;
	map->exit = 0;
	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			cell = map->grid[x][y];
			if (cell == 'P')
				map->player++;
			else if (cell == 'E')
				map->exit++;
			else if (cell == 'C')
				map->collectable++;
			else if (cell != '0' && cell != '1' && cell != '\n')
				check_invalid_char(cell);
			y++;
		}
		x++;
	}
}

void check_map_char(t_map *map)
{
    
    if (map->player != 1 || map->exit != 1 || map->collectable < 1)
        ft_error("El contenido el mapa no es validp");
}

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
// funcion que verifique si es rectangular 
// funcion que verifique si si es horizontal o vertical
