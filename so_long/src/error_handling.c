#include "../so_long.h"

// Cada celda sea uno de los validos 
void ft_error(const char *msg)
{
    if (msg)
    {
        perror(msg);
    }
    perror("Error");
    exit(EXIT_FAILURE);
}

/*
0: Representa un espacio vacío en el mapa.
1: Representa una pared en el mapa.
P: Representa la posición inicial del jugador.
E: Representa la salida del mapa.
C: Representa un coleccionable que el jugador debe recoger.
*/

void check_char(int i)
{
    if(!(ft_strchr("01PEC", i)))
        ft_error("caracter no existe\n");
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
