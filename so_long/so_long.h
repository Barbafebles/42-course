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
    int     count;
}   t_player;            // Faltaba el nombre del tipo y punto y coma

typedef struct s_game 
{
    mlx_t   *mlx;       // Cambiado a mlx_t* para MLX42
    char    **map;
    char    *path;
    int     window_width;
    t_player player;    // Añadido el jugador a la estructura del juego
}   t_game;

#endif