#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "libft/libft.h"
//# include "get_next_line/get_next_line.h"
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
    char **grid;
    int player;
    int exit;
    int collectable;
    size_t width;
    size_t height;
}   t_map;

void check_char(int i);
void check_map(t_map *map);
void check_map_char(t_map *map);
void check_wall(t_map *map);
void check_recta(t_map *map);
void check_extension(char *filename);
void find_player(t_map *map, int *p_x, int *p_y);
char **copy_map(t_map *map);
void flood_fill(char **map, int x, int y, int height, int width);
int check_path(t_map *map);
void check_file(char *filename);
void check_empty_map(t_map *map);
int load_map(char *filename, t_map *map);
void free_map(t_map *map);

#endif
