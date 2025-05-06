/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:12:05 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/06 12:22:07 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_map(t_game *game)
{
	size_t	y;

	ft_printf("Mapa:\n");
	y = 0;
	while (game->map.grid[y] != NULL)
	{
		ft_printf("%s\n", game->map.grid[y]);
		y++;
	}
}

void	init_player_image(t_game *game)
{
	size_t	y;
	size_t	x;

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
				game->images.player_img = load_xpm_image(game->mlx,
						"./xpm/cochemax.png");
				if (!game->images.player_img)
					ft_error("Error al cargar la imagen del jugador");
				mlx_image_to_window(game->mlx, game->images.player_img, x
					* TILE_SIZE, y * TILE_SIZE);
				return ;
			}
			x++;
		}
		y++;
	}
}
