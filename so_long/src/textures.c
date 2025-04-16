/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:58:21 by bfebles-          #+#    #+#             */
/*   Updated: 2025/04/16 18:20:46 by bfebles-         ###   ########.fr       */
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

void    load_textures(t_game *game)
{
    game->images.casco_imgs = NULL;
    game->images.num_cascos = 0;

    game->images.asfalto_img = load_xpm_image(game->mlx, "./xpm/asfalto.png");
    game->images.grada_img = load_xpm_image(game->mlx, "./xpm/grada.png");
    game->images.cocheMax_img = load_xpm_image(game->mlx, "./xpm/cocheMax.png");
    
    if (!game->images.asfalto_img || !game->images.grada_img || 
        !game->images.cocheMax_img)
        ft_error("Error al cargar las texturas");
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

/*
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
			mlx_image_to_window(game->mlx, game->images.grada_img, x
			* TILE_SIZE, y * TILE_SIZE);
			else if (game->map.grid[y][x] == 'P')
			mlx_image_to_window(game->mlx, game->images.cocheMax_img, x
			* TILE_SIZE, y * TILE_SIZE);
			else if (game->map.grid[y][x] == 'C')
			mlx_image_to_window(game->mlx, game->images.casco_img, x
			* TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
*/
void    render_static_map(t_game *game)
{
    size_t  y;
    size_t  x;
    int     casco_index;

    // Inicializar variables
    game->images.num_cascos = 0;
    casco_index = 0;

    // Contar cascos
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

    // Crear nuevo array de cascos
    game->images.casco_imgs = malloc(sizeof(mlx_image_t*) * (game->images.num_cascos + 1));
    if (!game->images.casco_imgs)
        ft_error("Error al asignar memoria para las imágenes de cascos");

    // Renderizar el mapa
    y = 0;
    while (game->map.grid[y])
    {
        x = 0;
        while (game->map.grid[y][x])
        {
            // Siempre poner el asfalto primero
            mlx_image_to_window(game->mlx, game->images.asfalto_img, x * TILE_SIZE, y * TILE_SIZE);
            
            // Luego los otros elementos
            if (game->map.grid[y][x] == '1')
                mlx_image_to_window(game->mlx, game->images.grada_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map.grid[y][x] == 'C')
            {
                // Intentar primero con cascoMax_64.png que parece ser el más adecuado para el tamaño
                game->images.casco_imgs[casco_index] = load_xpm_image(game->mlx, "./xpm/cascoMax_64.png");
                if (!game->images.casco_imgs[casco_index])
                {
                    // Si falla, intentar con cascoMax.png
                    game->images.casco_imgs[casco_index] = load_xpm_image(game->mlx, "./xpm/cascoMax.png");
                    if (!game->images.casco_imgs[casco_index])
                        ft_error("Error al cargar imagen de casco");
                }
                
                // Imprimir información de depuración
                printf("Cargando casco en posición (%zu, %zu)\n", x, y);
                
                mlx_image_to_window(game->mlx, game->images.casco_imgs[casco_index], x * TILE_SIZE, y * TILE_SIZE);
                casco_index++;
            }
            x++;
        }
        y++;
    }
    
    // Imprimir información de depuración
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
