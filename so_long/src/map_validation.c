#include "../so_long.h"

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
    {
        ft_error("El contenido del mapa no es valido");
    }
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

// Verificar si todos los elementos importantes son accesibles
int check_path(t_map *map)
{
    size_t i;
    size_t j;
    t_path_check path;
    path.temp_map = copy_map(map);
    if (!path.temp_map)
        ft_error("Error de memoria al verificar el camino");
    find_player(map, &path.player_x, &path.player_y);
    flood_fill(path.temp_map, path.player_x, path.player_y, map->height, map->width);
    path.valid = 1; 
    i = 0; 
    while (i < map->height && path.valid)
    {
        j = 0;
        while (j < map->width && path.valid)
        {
            if (map->grid[i][j] == 'C' || (map->grid[i][j] == 'E' && path.temp_map[i][j] != 'F'))
                path.valid = 0;
            j++;
        }
        i++;
    }
    i = 0; 
    while(i < map->height)
        free(path.temp_map[i++]);
    free(path.temp_map);
    if(!path.valid)
        ft_error("No hay un camino valido para completar el nivel");
    return (path.valid);
}
