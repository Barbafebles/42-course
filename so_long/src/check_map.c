/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:49:34 by bfebles-          #+#    #+#             */
/*   Updated: 2025/03/22 00:13:41 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
/*
0: Representa un espacio vacío en el mapa.
1: Representa una pared en el mapa.
P: Representa la posición inicial del jugador.
E: Representa la salida del mapa.
C: Representa un coleccionable que el jugador debe recoger.
*/
// Cada celdad sea uno de los validos 
void ft_error(const char *msg)
{
    if (msg)
    {
        perror(msg);
    }
    perror("Error");
    exit(EXIT_FAILURE);
}

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

// validacion archivo del mapa .ber 
void check_extension(char *filename)
{
    size_t len;
    len = ft_strlen(filename);
    if (len < 4 || ft_strncmp(&filename[len - 4], ".ber", 4) != 0)
    {
        ft_error("la extension del mapa no es la correcta.");
    }
}

// funcion para encontrar el jugador
void find_player(t_map *map, int *p_x, int *p_y)
{
    size_t x;
    size_t y; 
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
                return; 
            }
            y++;
        }
        x++;
    }
}

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
    
    // Explorar en 4 direcciones
    flood_fill(map, x + 1, y, height, width);
    flood_fill(map, x - 1, y, height, width);
    flood_fill(map, x, y + 1, height, width);
    flood_fill(map, x, y - 1, height, width);
}

// Verificar si todos los elementos importantes son accesibles
int check_path(t_map *map)
{
    char **temp_map;
    int player_x;
    int player_y;
    size_t i;
    size_t j;
    int valid;
    
    temp_map = copy_map(map);
    if (!temp_map)
        ft_error("Error de memoria al verificar el camino");
    
    find_player(map, &player_x, &player_y);
    
    // Realizar flood fill desde la posición del jugador
    flood_fill(temp_map, player_x, player_y, map->height, map->width);
    
    // Verificar que todos los coleccionables y la salida son accesibles
    valid = 1;
    i = 0;
    while (i < map->height && valid)
    {
        j = 0;
        while (j < map->width && valid)
        {
            if ((map->grid[i][j] == 'C' || map->grid[i][j] == 'E') && temp_map[i][j] != 'F')
                valid = 0;
            j++;
        }
        i++;
    }
    
    // Liberar memoria
    i = 0;
    while (i < map->height)
        free(temp_map[i++]);
    free(temp_map);
    
    if (!valid)
        ft_error("No hay un camino válido para completar el nivel");
    
    return (valid);
}

void check_file(char *filename)
{
    int fd;
    
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        ft_error("No se puede abrir el archivo");
    close(fd);
}

void check_empty_map(t_map *map)
{
    if (map->height == 0 || map->width == 0)
        ft_error("El mapa está vacío");
}

// Cargar mapa desde archivo
// Cargar mapa desde archivo
// Función auxiliar para contar líneas en un archivo
static size_t count_lines(char *filename)
{
    int fd;
    char buffer[4096];
    ssize_t bytes_read;
    size_t count = 0;
    ssize_t i; // Cambiado de size_t a ssize_t para coincidir con bytes_read
    
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (0);
    
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
    {
        for (i = 0; i < bytes_read; i++)
        {
            if (buffer[i] == '\n')
                count++;
        }
    }
    
    // Si el archivo no termina con nueva línea, añadir una línea más
    if (bytes_read > 0 && buffer[bytes_read - 1] != '\n')
        count++;
    
    close(fd);
    return (count);
}

// Función auxiliar para leer una línea
static char *read_line(int fd)
{
    char buffer[4096];
    char *line = NULL;
    // Eliminada la variable temp que no se usa
    ssize_t bytes_read;
    ssize_t i; // Cambiado de size_t a ssize_t
    size_t start = 0;
    
    bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read <= 0)
        return (NULL);
    
    for (i = 0; i < bytes_read; i++)
    {
        if (buffer[i] == '\n')
        {
            buffer[i] = '\0';
            line = ft_strdup(&buffer[start]);
            // Mover el puntero del archivo
            lseek(fd, -(bytes_read - i - 1), SEEK_CUR);
            return (line);
        }
    }
    
    // Si no hay salto de línea, duplicar todo el buffer
    line = ft_strdup(buffer);
    return (line);
}

// Cargar mapa desde archivo
int load_map(char *filename, t_map *map)
{
    int fd;
    size_t i;
    
    // Contar líneas
    map->height = count_lines(filename);
    if (map->height == 0)
        return (0);
    
    // Abrir archivo
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (0);
    
    // Asignar memoria para la matriz
    map->grid = (char **)malloc(sizeof(char *) * (map->height + 1));
    if (!map->grid)
    {
        close(fd);
        return (0);
    }
    
    // Leer líneas
    for (i = 0; i < map->height; i++)
    {
        map->grid[i] = read_line(fd);
        if (!map->grid[i])
        {
            while (i > 0)
                free(map->grid[--i]);
            free(map->grid);
            close(fd);
            return (0);
        }
    }
    map->grid[i] = NULL;
    
    // Establecer ancho
    if (map->height > 0)
        map->width = ft_strlen(map->grid[0]);
    
    close(fd);
    return (1);
}

// Liberar memoria del mapa
void free_map(t_map *map)
{
    size_t i;
    
    if (map->grid)
    {
        i = 0;
        while (i < map->height)
        {
            free(map->grid[i]);
            i++;
        }
        free(map->grid);
    }
}


int main(int argc, char **argv)
{
    t_map map;
    
    if (argc != 2)
    {
        printf("Uso: %s [archivo.ber]\n", argv[0]);
        return (1);
    }
    
    // Inicializar estructura del mapa
    ft_memset(&map, 0, sizeof(t_map));
    
    // Verificar extensión del archivo
    check_extension(argv[1]);
    
    // Cargar el mapa (deberás implementar esta función)
    if (!load_map(argv[1], &map))
    {
        printf("Error al cargar el mapa\n");
        return (1);
    }
    
    // Ejecutar verificaciones
    check_recta(&map);
    check_map(&map);
    check_map_char(&map);
    check_wall(&map);
    
    // Si llegas aquí, el mapa es válido (excepto por el path checking)
    printf("El mapa ha pasado todas las verificaciones implementadas hasta ahora\n");

    free_map(&map);
    
    return (0);
}

// camino valido super importante 
// ahora a ver los controles de las teclas, verlas para saber cual es cual es linux para ver cuando se pulsa cada una. 
// Como hace el movimiento, como hacer que se mueva el muneco (yo pinto el cuadradito no lo muevo y pinto un suelo como por capas)
// identificar celda personaje -> celda -> personaje
// con las letras. Con las letras. 
