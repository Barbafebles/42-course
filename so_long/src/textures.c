/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:58:21 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/03 12:32:12 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_image_t	*load_xpm_image(mlx_t *mlx, const char *file_path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(file_path);
	if (texture == NULL)
	{
		printf("Error: No se pudo cargar %s\n", file_path);
		ft_error("Error al cargar imagen");
	}
	img = mlx_texture_to_image(mlx, texture);
	if (img == NULL)
	{
		mlx_delete_texture(texture);
		ft_error("Error al convertir textura a imagen");
	}
	mlx_delete_texture(texture);
	return (img);
}

void	load_textures(t_game *game)
{
	game->images.casco_imgs = NULL;
	game->images.num_cascos = 0;
	game->images.asfalto_img = load_xpm_image(game->mlx, "./xpm/asfalto.png");
	game->images.grada_img = load_xpm_image(game->mlx, "./xpm/grada.png");
	game->images.cochemax_img = load_xpm_image(game->mlx, "./xpm/cochemax.png");
	game->images.exit_img = load_xpm_image(game->mlx, "./xpm/salida.png");
	if (game->images.asfalto_img == NULL || game->images.grada_img == NULL
		|| game->images.cochemax_img == NULL)
		ft_error("Error al cargar las texturas");
}

void	cleanup_images(t_game *game)
{
	int	i;

	if (game->images.asfalto_img)
		mlx_delete_image(game->mlx, game->images.asfalto_img);
	if (game->images.grada_img)
		mlx_delete_image(game->mlx, game->images.grada_img);
	if (game->images.cochemax_img)
		mlx_delete_image(game->mlx, game->images.cochemax_img);
	if (game->images.exit_img)
		mlx_delete_image(game->mlx, game->images.exit_img);
	if (game->images.player_img)
		mlx_delete_image(game->mlx, game->images.player_img);
	if (game->images.casco_imgs)
	{
		i = 0;
		while (i < game->images.num_cascos)
		{
			if (game->images.casco_imgs[i])
				mlx_delete_image(game->mlx, game->images.casco_imgs[i]);
			i++;
		}
		free(game->images.casco_imgs);
		game->images.casco_imgs = NULL;
	}
}
