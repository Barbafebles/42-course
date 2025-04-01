#include "../so_long.h"

// Cargar mapa desde archivo
// Función auxiliar para cargar las líneas del mapa
static int load_map_lines(int fd, t_map *map)
{
    size_t i = 0;

    while (i < map->height)
    {
        map->grid[i] = read_line(fd);
        if (!map->grid[i])
        {
            while (i > 0)
                free(map->grid[--i]);
            free(map->grid);
            return (0);
        }
        i++;
    }
    map->grid[i] = NULL;
    return (1);
}
// Cargar mapa desde archivo
int load_map(char *filename, t_map *map)
{
    int fd;
    map->height = count_lines(filename);
    if (map->height == 0)
        return (0);
    fd = open(filename, O_RDONLY);
    printf("Pasa por open\n");
    if (fd < 0)
        return (0);
    map->grid = (char **)malloc(sizeof(char *) * (map->height + 1));
    if (!map->grid)
    {
        close(fd);
        return (0);
    }
    if (!load_map_lines(fd, map))
    {
        close(fd);
        return (0);
    }
    map->width = (map->height > 0) ? ft_strlen(map->grid[0]) : 0;
    close(fd);
    return (1);
}

// Cargar mapa desde archivo
// Cargar mapa desde archivo
// Función auxiliar para contar líneas en un archivo
size_t count_lines(char *filename)
{
    int fd;
    char buffer[4096];
    ssize_t bytes_read;
    size_t count = 0;
    ssize_t i;
    
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
    if (bytes_read > 0 && buffer[bytes_read - 1] != '\n')
        count++;
    
    close(fd);
    return (count);
}

// Función auxiliar para leer una línea
char *read_line(int fd)
{
    char buffer[4096];
    char *line = NULL;
    ssize_t bytes_read;
    ssize_t i;
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
            lseek(fd, -(bytes_read - i - 1), SEEK_CUR);
            return (line);
        }
    }
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


