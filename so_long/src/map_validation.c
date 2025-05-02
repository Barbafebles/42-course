/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:57:27 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/01 20:15:41 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// recorro toda la matriz y llamo a check_char si encuentra algo que no es 0 y 1
void    check_map(t_map *map)
{
    size_t  x;
    size_t  y;

    map->player = 0;
    map->collectable = 0;
    map->exit = 0;
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
    printf("Collectables: %d\n", map->collectable);
}

// chequear que el mapa tiene los limites del mapa
void    check_map_char(t_map *map)
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

// Chequea que las paredes sean 1 (que el mapa este cerrado)
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
// verifica si existe un camino válido para que el jugador alcance todos los objetivos.
// Se realiza creando una copia temporal del mapa y aplicando un algoritmo de 'flood fill' para marcar 
// las casillas alcanzables.
int check_path(t_map *map)
{
    t_path  path;
    int     result;
    size_t  i;
    size_t  j;

    // Inicializar el mapa temporal
    path.temp_map = (char **)malloc(sizeof(char *) * (map->height));
    if (!path.temp_map)
        return (0);
    
    // Copiar el mapa y encontrar la posición del jugador
    i = 0;
    while (i < map->height)
    {
        path.temp_map[i] = ft_strdup(map->grid[i]);
        j = 0;
        while (j < map->width)
        {
            // Guardar las coordenadas del jugador correctamente
            if (map->grid[i][j] == 'P')
            {
                path.player_x = i;  // Coordenada Y (fila)
                path.player_y = j;  // Coordenada X (columna)
            }
            j++;
        }
        i++;
    }

    // Ejecutar flood fill y verificar objetivos
    execute_flood_fill(&path, map);
    result = check_reachable_objectives(map, path.temp_map);

    // Liberar memoria
    free_temp_map(path.temp_map, map->height);

    return (result);
}
// check_reachable_objectives recorre el mapa original y verifica en la copia temporal (tras el flood fill)
// que cada objetivo (coleccionable 'C' o salida 'E') haya sido visitado (marcado con 'F').
// Si alguno no fue visitado, significa que no es alcanzable y retorna 0.
int check_reachable_objectives(t_map *map, char **temp_map)
{
    size_t  i;
    size_t  j;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if ((map->grid[i][j] == 'C' || map->grid[i][j] == 'E') 
                && temp_map[i][j] != 'F')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
// Guarda la posición de la salida ('E') en el mapa.
// Recorre cada casilla y, al encontrar la salida, almacena sus coordenadas en map->exit_x y map->exit_y.
void    save_exit_position(t_map *map)
{
    size_t  x;
    size_t  y;

    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (map->grid[y][x] == 'E')
            {
                map->exit_x = x;
                map->exit_y = y;
                return;
            }
            x++;
        }
        y++;
    }
}
// Libera la memoria utilizada por la copia temporal del mapa.
// Recorre cada línea asignada en temp_map y la libera, luego libera el arreglo de punteros.
void    free_temp_map(char **temp_map, size_t height)
{
    size_t i;

    if (!temp_map)
        return;
    i = 0;
    while (i < height)
    {
        if (temp_map[i])
            free(temp_map[i]);
        i++;
    }
    free(temp_map);
}
// Verifica que el tamaño del mapa cumpla ciertos criterios mínimos y máximos.
// Se asegura de que el mapa no sea demasiado pequeño ni demasiado grande, y que tenga el espacio
// suficiente para los elementos necesarios.
void    check_map_size(t_map *map)
{
    if (!map || !map->grid)
        ft_error("Mapa inválido");

    if (map->height < 3 || map->width < 3)
        ft_error("El mapa es demasiado pequeño (mínimo 3x3)");

    if (map->height > 50 || map->width > 50)
        ft_error("El mapa es demasiado grande (máximo 50x50)");

    if (map->width * map->height < 9)
        ft_error("El mapa no tiene suficiente espacio para todos los elementos necesarios");
}

void	validate_map_complete(t_map *map)
{  // Verifica la extensión del archivo
	check_empty_map(map);     // Verifica que el mapa no esté vacío
	check_map_size(map);      // Verifica dimensiones mínimas y máximas
	check_recta(map);         // Verifica que sea rectangular
	check_wall(map);          // Verifica las paredes
	check_map(map);           // Cuenta elementos (P, E, C)
	check_map_char(map); 
    save_exit_position(map);    // Verifica cantidad correcta de elementos
	if (!check_path(map))     // Verifica que exista un camino válido
		ft_error("No hay un camino válido para completar el nivel");
}