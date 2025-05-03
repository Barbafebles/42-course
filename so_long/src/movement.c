/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:28:19 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/03 12:30:17 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	is_valid_move(t_game *g, int x, int y)
{
	char	c;

	if (y < 0 || y >= (int)g->map.height || x < 0 || x >= (int)g->map.width)
		return (false);
	c = g->map.grid[y][x];
	return (c == '0' || c == 'C' || c == 'E');
}

static void	update_grid_and_image(t_game *g, int x, int y, char next)
{
	if (next == 'C')
		check_collectible(g, x, y);
	if (g->player_x == g->map.exit_x && g->player_y == g->map.exit_y)
		g->map.grid[g->player_y][g->player_x] = 'E';
	else
		g->map.grid[g->player_y][g->player_x] = '0';
	g->map.grid[y][x] = 'P';
	g->player_x = x;
	g->player_y = y;
	if (g->images.player_img)
		mlx_delete_image(g->mlx, g->images.player_img);
	g->images.player_img = load_xpm_image(g->mlx, "./xpm/cochemax.png");
	if (!g->images.player_img)
		ft_error("Error al cargar la imagen del jugador");
	mlx_image_to_window(g->mlx, g->images.player_img, x * TILE_SIZE, y
		* TILE_SIZE);
}

static void	finish_move(t_game *g, int x, int y, char next)
{
	if (next == 'E')
		check_exit(g, x, y);
	printf("Movimientos realizados: %d\n", g->moves);
	g->moves++;
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	next;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	next = game->map.grid[new_y][new_x];
	if (!is_valid_move(game, new_x, new_y))
		return ;
	update_grid_and_image(game, new_x, new_y, next);
	finish_move(game, new_x, new_y, next);
}
