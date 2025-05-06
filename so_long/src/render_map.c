/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:15:45 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/03 12:31:40 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	prepare_casco_array(t_game *game)
{
	size_t	y;
	size_t	x;
	size_t	count;

	count = 0;
	y = 0;
	while (game->map.grid[y] != NULL)
	{
		x = 0;
		while (game->map.grid[y][x] != '\0')
		{
			if (game->map.grid[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	game->images.num_cascos = count;
	game->images.casco_imgs = malloc(sizeof(mlx_image_t *) * (count + 1));
	if (game->images.casco_imgs == NULL)
		ft_error("Error al asignar memoria para cascos");
}

static void	draw_collectible_tile(t_game *game, size_t x, size_t y, size_t *idx)
{
	game->images.casco_imgs[*idx] = load_xpm_image(game->mlx,
			"./xpm/cascomax_64.png");
	if (game->images.casco_imgs[*idx] == NULL)
		ft_error("Error al cargar imagen de casco");
	mlx_image_to_window(game->mlx, game->images.casco_imgs[*idx], x * TILE_SIZE,
		y * TILE_SIZE);
	(*idx)++;
}

static void	draw_tile(t_game *game, size_t x, size_t y, size_t *idx)
{
	char	cell;

	cell = game->map.grid[y][x];
	mlx_image_to_window(game->mlx, game->images.asfalto_img, x * TILE_SIZE, y
		* TILE_SIZE);
	if (cell == '1')
		mlx_image_to_window(game->mlx, game->images.grada_img, x * TILE_SIZE, y
			* TILE_SIZE);
	else if (cell == 'C')
		draw_collectible_tile(game, x, y, idx);
	else if (cell == 'E')
		mlx_image_to_window(game->mlx, game->images.exit_img, x * TILE_SIZE, y
			* TILE_SIZE);
}

static void	draw_tiles(t_game *game)
{
	size_t	y;
	size_t	x;
	size_t	idx;

	idx = 0;
	y = 0;
	while (game->map.grid[y] != NULL)
	{
		x = 0;
		while (game->map.grid[y][x] != '\0')
		{
			draw_tile(game, x, y, &idx);
			x++;
		}
		y++;
	}
}

void	render_static_map(t_game *game)
{
	prepare_casco_array(game);
	draw_tiles(game);
	ft_printf("Total de cascos cargados: %d\n", game->images.num_cascos);
}
