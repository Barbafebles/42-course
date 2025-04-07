/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:03:16 by bfebles-          #+#    #+#             */
/*   Updated: 2025/04/07 19:27:06 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_player(t_game *game, int dx, int dy)
{
	int x, y;
	int new_x, new_y;
	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (game->map.grid[y][x] == 'P')
			{
				new_x = x + dx;
				new_y = y + dy;
				if (new_y >= 0 && new_y < (int)game->map.height && new_x >= 0
					&& new_x < (int)game->map.width
					&& (game->map.grid[new_y][new_x] == '0'
						|| game->map.grid[new_y][new_x] == 'C'
						|| game->map.grid[new_y][new_x] == 'E'))
				{
					game->map.grid[y][x] = '0';
					game->map.grid[new_y][new_x] = 'P';
				}
				return ;
			}
			x++;
		}
		y++;
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		else if (keydata.key == MLX_KEY_W)
			move_player(game, 0, -1);
		else if (keydata.key == MLX_KEY_S)
			move_player(game, 0, 1);
		else if (keydata.key == MLX_KEY_A)
			move_player(game, -1, 0);
		else if (keydata.key == MLX_KEY_D)
			move_player(game, 1, 0);
		// Una vez actualizado el movimiento, se re-renderiza el mapa:
		render_map(game);
	}
}
