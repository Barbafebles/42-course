#include "../so_long.h"

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

