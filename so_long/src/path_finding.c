#include "../so_long.h"

// Crear una copia del mapa para flood fill
char **copy_map(t_map *map)
{
    char **copy;
    size_t i;
    
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

// Algoritmo de flood fill recursivo
void flood_fill(char **map, int x, int y, int height, int width)
{
    if (x < 0 || y < 0 || x >= height || y >= width || 
        map[x][y] == '1' || map[x][y] == 'F')
        return;
    
    // 'F' marca casillas visitadas
    map[x][y] = 'F';
    flood_fill(map, x + 1, y, height, width);
    flood_fill(map, x - 1, y, height, width);
    flood_fill(map, x, y + 1, height, width);
    flood_fill(map, x, y - 1, height, width);
}