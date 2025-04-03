/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:58:21 by bfebles-          #+#    #+#             */
/*   Updated: 2025/04/02 11:10:01 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_image_t	*load_xpm_image(mlx_t *mlx, const char *file_path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	printf("Cargando imagen: %s\n", file_path);
	texture = mlx_load_png(file_path);
	if (!texture)
	{
		printf("Error: No se pudo cargar %s\n", file_path);
		ft_error("Error al cargar imagen");
	}
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
	{
		mlx_delete_texture(texture);
		ft_error("Error al convertir textura a imagen");
	}
	mlx_delete_texture(texture);
	return (img);
}

void	load_textures(t_game *game)
{
	game->images.asfalto_img = load_xpm_image(game->mlx, "./xpm/asfalto.png");
	if (!game->images.asfalto_img)
		ft_error("Error al cargar asfalto.png");
	game->images.cocheMax_img = load_xpm_image(game->mlx, "./xpm/cocheMax.png");
	if (!game->images.cocheMax_img)
		ft_error("Error al cargar cocheMax.png");
	game->images.casco_img = load_xpm_image(game->mlx, "./xpm/cascoMax.png");
	if (!game->images.casco_img)
		ft_error("Error al cargar cascoMax.png");
}

/*
void	load_textures(t_game *game)
{
	game->images.asfalto_img = load_xpm_image(game->mlx, "xpm/asfalto.xpm");
	if (!game->images.asfalto_img)
	ft_error("Error al cargar asfalto.xpm");
	game->images.cocheMax_img = load_xpm_image(game->mlx, "xpm/cocheMax.xpm");
	if (!game->images.cocheMax_img)
	ft_error("Error al cargar cocheMax.xpm");
	game->images.casco_img = load_xpm_image(game->mlx, "xpm/cascoMax.xpm");
	if (!game->images.casco_img)
	ft_error("Error al cargar cascoMax.xpm");
}
*/

void	print_map(t_game *game)
{
	size_t	y;

	y = 0;
	printf("Mapa:\n");
	while (game->map.grid[y])
	{
		printf("%s\n", game->map.grid[y]);
		y++;
	}
}

void	render_map(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	if (!game->map.grid)
		return ;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			mlx_image_to_window(game->mlx, game->images.asfalto_img, x
				* TILE_SIZE, y * TILE_SIZE);
			if (game->map.grid[y][x] == '1')
				mlx_image_to_window(game->mlx, game->images.cocheMax_img, x
					* TILE_SIZE, y * TILE_SIZE);
			if (game->map.grid[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->images.casco_img, x
					* TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	cleanup_images(t_game *game)
{
	if (game->images.asfalto_img)
		mlx_delete_image(game->mlx, game->images.asfalto_img);
	if (game->images.cocheMax_img)
		mlx_delete_image(game->mlx, game->images.cocheMax_img);
	if (game->images.casco_img)
		mlx_delete_image(game->mlx, game->images.casco_img);
}
