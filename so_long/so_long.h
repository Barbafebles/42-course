/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:12:50 by bfebles-          #+#    #+#             */
/*   Updated: 2025/04/16 18:29:20 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "libft/libft.h"
// # include "get_next_line/get_next_line.h"
# include <fcntl.h>  // Para open()
# include <stdio.h>  // Para perror(), printf()
# include <stdlib.h> // Para malloc(), free()
# include <unistd.h> // Para read(), close()

# define TILE_SIZE 64

typedef struct s_images
{
    mlx_image_t	*asfalto_img;
    mlx_image_t	**casco_imgs;  // Array de imágenes de coleccionables
    mlx_image_t	*cocheMax_img;
    mlx_image_t	*grada_img;
    mlx_image_t  *player_img;
    int         num_cascos;    // Número de cascos en el mapa
}               t_images;

typedef struct s_path
{
	char		**temp_map;
	int			player_x;
	int			player_y;
}				t_path;
typedef struct s_map_info
{
	char		**map;
	int			height;
	int			width;
}				t_map_info;
typedef struct s_player
{
	int			x;
	int			y;
	int count; /* movimientos */
}				t_player;

typedef struct s_map
{
    char    **grid;
    int     player;
    int     exit;
    int     collectable;
    size_t  width;
    size_t  height;
    int     exit_x;     // Añadir estas dos líneas
    int     exit_y;     // para las coordenadas de salida
}           t_map;

typedef struct s_game
{
    mlx_t		*mlx;      /* Instancia de MLX42 */
    t_map		map;       /* Información del mapa (incluye grid, dimensions, etc.) */
    t_images	images;
	int	player_x;
	int player_y;
    t_player	player;
    int			moves;     /* Contador de movimientos */
    // int			width;  
    // int			height;
}				t_game;

// typedef struct s_game
// {
// 	mlx_t		*mlx;   /* instancia de MLX42 */
// 	char		**map;  /* matriz del mapa */
// 	int			width;  /* ancho del mapa */
// 	int			height;
// 	t_images	images;
// 	t_player	player;
// }	t_game;

typedef struct s_path_check
{
	char		**temp_map;
	int			player_x;
	int			player_y;
	size_t		i;
	size_t		j;
	int			valid;
}				t_path_check;

// acomodar por archivos para no perderme
void			check_char(int i);
void			check_map(t_map *map);
void			check_map_char(t_map *map);
void			check_wall(t_map *map);
void			check_recta(t_map *map);
void			check_extension(char *filename);
void			find_player(t_map *map, int *p_x, int *p_y);
char			**copy_map(t_map *map);
void			flood_fill(t_map_info *map_info, int x, int y);
int				check_path(t_map *map);
void			check_file(char *filename);
void			check_empty_map(t_map *map);
int				load_map(char *filename, t_map *map);
void			free_map(t_map *map);
void			ft_error(const char *msg);
char			*read_line(int fd);
size_t			count_lines(char *filename);
/* texture */
mlx_image_t		*load_xpm_image(mlx_t *mlx, const char *file_path);
void			load_textures(t_game *game);
// void			render_map(t_game *game);
void	render_static_map(t_game *game);
void	init_player_image(t_game *game);
void	move_player(t_game *game, int dx, int dy);
void			cleanup_images(t_game *game);
void			print_map(t_game *game);
void	check_collectible(t_game *game, int x, int y);
void    save_exit_position(t_map *map);
int check_reachable_objectives(t_map *map, char **temp_map);
void    validate_complete_map(t_map *map);

/* vale esto es */
int				open_map_file(char *filename);
int				init_map(t_map *map, char *filename);
int				load_map_lines(int fd, t_map *map);
/* Hooks */
void	key_hook(mlx_key_data_t keydata, void *param);
void    check_map_size(t_map *map);
void    free_temp_map(char **temp_map, size_t height);
#endif
