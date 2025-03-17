#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include <fcntl.h>       // Para open()
# include <unistd.h>      // Para read(), close()
# include <stdlib.h>      // Para malloc(), free()
# include <stdio.h>       // Para perror(), printf()   

typedef struct s_player
{
    int     x;
    int     y;
    int     count; // movimientos 
}   t_player;       

typedef struct s_game 
{
    mlx_t   *mlx;  // instancia de MLX42
    char    **map;  // matriz del mapa 
    int      width; // ancho del mapa
    int     height;
    t_player player;  // alto del mapa
}   t_game;

typedef struct s_map
{
    char **grip;
    int player;
    int exit;
    int collectable;
    size_t width;
    size_t height;
}   t_map;

#endif
