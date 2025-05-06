/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:12:50 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/05 19:25:10 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
#include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 64

typedef struct s_images
{
	mlx_image_t	*asfalto_img;
	mlx_image_t	**casco_imgs;
	mlx_image_t	*cochemax_img;
	mlx_image_t	*grada_img;
	mlx_image_t	*player_img;
	mlx_image_t	*exit_img;
	int			num_cascos;
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
	int			count;
}				t_player;

typedef struct s_map
{
	char		**grid;
	int			player;
	int			exit;
	int			collectable;
	size_t		width;
	size_t		height;
	int			exit_x;
	int			exit_y;
}				t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		map;
	t_images	images;
	int			player_x;
	int			player_y;
	t_player	player;
	int			moves;
}				t_game;

typedef struct s_path_check
{
	char		**temp_map;
	int			player_x;
	int			player_y;
	size_t		i;
	size_t		j;
	int			valid;
}				t_path_check;

/* error_handling OK */
void			check_char(int i);
void			check_file(char *filename);
void			check_empty_map(t_map *map);
void			check_extension(char *filename);
void			find_player(t_map *map, int *p_x, int *p_y);

/* hook OK */
void			check_exit(t_game *game, int x, int y);
void			key_hook(mlx_key_data_t keydata, void *param);

/* map_load OK*/
int				load_map_lines(int fd, t_map *map);
int				init_map(t_map *map, char *filename);
int				load_map(char *filename, t_map *map);

/* map_count OK*/
size_t			count_lines(char *filename);

/* map_file OK*/
int				open_map_file(char *filename);
char			*read_line(int fd);
void			free_map(t_map *map);

/* map_validate_basic OK*/
void			check_map(t_map *map);
void			check_map_char(t_map *map);
void			check_wall(t_map *map);
void			check_recta(t_map *map);

/* map_validate_size OK*/
void			check_map_size(t_map *map);
void			save_exit_position(t_map *map);

/* map_validate_path OK*/
int				check_path(t_map *map);

/* map_validate_complete OK*/
void			validate_map_complete(t_map *map);

/* movement OK*/
void			move_player(t_game *game, int dx, int dy);

/* path_finding OK*/
char			**copy_map(t_map *map);
void			flood_fill(t_map_info *map_info, int x, int y);
void			execute_flood_fill(t_path *path, t_map *map);

/* textures OK*/
mlx_image_t		*load_xpm_image(mlx_t *mlx, const char *file_path);
void			load_textures(t_game *game);
void			cleanup_images(t_game *game);

/* render_utils OK*/
void			print_map(t_game *game);
void			init_player_image(t_game *game);

/* render map OK*/
void			render_static_map(t_game *game);

/* utils */
void			ft_error(const char *msg);
void			check_collectible(t_game *game, int x, int y);

#endif
