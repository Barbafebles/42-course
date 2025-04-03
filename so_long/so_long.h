/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:12:50 by bfebles-          #+#    #+#             */
/*   Updated: 2025/04/03 17:38:58 by bfebles-         ###   ########.fr       */
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
	mlx_image_t	*casco_img; /*coleccionable*/
	mlx_image_t	*cocheMax_img;
	// mlx_image_t	*exit_img;
	// mlx_image_t	*player_img;
}				t_images;
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
	char		**grid;
	int			player;
	int			exit;
	int			collectable;
	size_t		width;
	size_t		height;
}				t_map;
typedef struct s_game
{
	mlx_t *mlx; /* instancia de MLX42 */
	t_map map;  /* estructura del mapa */
	int width;  /* ancho del mapa */
	int			height;
	t_images	images;
	t_player	player;
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
void			render_map(t_game *game);
void			cleanup_images(t_game *game);
void			print_map(t_game *game);
/* vale esto es */
int				open_map_file(char *filename);
int				init_map(t_map *map, char *filename);
int				load_map_lines(int fd, t_map *map);
#endif
