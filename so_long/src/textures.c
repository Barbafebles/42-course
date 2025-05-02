/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:58:21 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/02 20:09:09 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_image_t	*load_xpm_image(mlx_t *mlx, const char *file_path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

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

void    load_textures(t_game *game)
{
    game->images.casco_imgs = NULL;
    game->images.num_cascos = 0;

    game->images.asfalto_img = load_xpm_image(game->mlx, "./xpm/asfalto.png");
    game->images.grada_img = load_xpm_image(game->mlx, "./xpm/grada.png");
    game->images.cocheMax_img = load_xpm_image(game->mlx, "./xpm/cocheMax.png");
	game->images.exit_img = load_xpm_image(game->mlx, "./xpm/salida.png");
    if (!game->images.exit_img)
        ft_error("No se pudo cargar la textura de la salida");
    
    if (!game->images.asfalto_img || !game->images.grada_img || 
        !game->images.cocheMax_img)
        ft_error("Error al cargar las texturas");
}

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

void    render_static_map(t_game *game)
{
    size_t  y;
    size_t  x;
    int     casco_index;

    game->images.num_cascos = 0;
    casco_index = 0;

    y = 0;
    while (game->map.grid[y])
    {
        x = 0;
        while (game->map.grid[y][x])
        {
            if (game->map.grid[y][x] == 'C')
                game->images.num_cascos++;
            x++;
        }
        y++;
    }
    game->images.casco_imgs = malloc(sizeof(mlx_image_t*) * (game->images.num_cascos + 1));
    if (!game->images.casco_imgs)
        ft_error("Error al asignar memoria para las imágenes de cascos");

    y = 0;
    while (game->map.grid[y])
    {
        x = 0;
        while (game->map.grid[y][x])
        {
            mlx_image_to_window(game->mlx, game->images.asfalto_img, x * TILE_SIZE, y * TILE_SIZE);

            if (game->map.grid[y][x] == '1')
                mlx_image_to_window(game->mlx, game->images.grada_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map.grid[y][x] == 'C')
            {
                game->images.casco_imgs[casco_index] = load_xpm_image(game->mlx, "./xpm/cascoMax_64.png");
                if (!game->images.casco_imgs[casco_index])
                {
                    game->images.casco_imgs[casco_index] = load_xpm_image(game->mlx, "./xpm/cascoMax.png");
                    if (!game->images.casco_imgs[casco_index])
                        ft_error("Error al cargar imagen de casco");
                }
                
                mlx_image_to_window(game->mlx, game->images.casco_imgs[casco_index], x * TILE_SIZE, y * TILE_SIZE);
                casco_index++;
            }
			else if (game->map.grid[y][x] == 'E')
			mlx_image_to_window(game->mlx, game->images.exit_img, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
    printf("Total de cascos cargados: %d\n", casco_index);
}
void	init_player_image(t_game *game)
{
	int	x;
	int y;

	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (game->map.grid[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				game->images.player_img = load_xpm_image(game->mlx, "./xpm/cocheMax.png");
				if (!game->images.player_img)
					ft_error("Error al cargar la imagen del jugador");
				mlx_image_to_window(game->mlx, game->images.player_img,
					x * TILE_SIZE, y * TILE_SIZE);
				return ;
			}
			x++;
		}
		y++;
	}
}

void    cleanup_images(t_game *game)
{
    int i;
    
    if (game->images.asfalto_img)
        mlx_delete_image(game->mlx, game->images.asfalto_img);
    if (game->images.grada_img)
        mlx_delete_image(game->mlx, game->images.grada_img);
    if (game->images.cocheMax_img)
        mlx_delete_image(game->mlx, game->images.cocheMax_img);
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
