/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:58:34 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/03 12:23:01 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_collectible_index(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->images.num_cascos)
	{
		if (game->images.casco_imgs[i] && game->images.casco_imgs[i]->instances
			&& game->images.casco_imgs[i]->instances[0].x == x * TILE_SIZE
			&& game->images.casco_imgs[i]->instances[0].y == y * TILE_SIZE)
			return (i);
		i++;
	}
	return (-1);
}

static void	handle_collectible_at_index(t_game *game, int idx, int y, int x)
{
	mlx_delete_image(game->mlx, game->images.casco_imgs[idx]);
	game->images.casco_imgs[idx] = NULL;
	game->map.grid[y][x] = '0';
	game->map.collectable--;
	printf("¡Casco recogido! Quedan: %d\n", game->map.collectable);
	if (game->map.collectable == 0)
		printf("\n¡Has recogido todos los cascos! Dirígete a la salida.\n");
}

void	check_collectible(t_game *game, int x, int y)
{
	int	idx;

	if (!game || !game->map.grid || !game->images.casco_imgs || !game->mlx)
		return ;
	if (game->map.grid[y][x] != 'C')
		return ;
	idx = get_collectible_index(game, x, y);
	if (idx < 0)
		return ;
	handle_collectible_at_index(game, idx, y, x);
}

void	ft_error(const char *msg)
{
	if (msg)
		perror(msg);
	perror("Error");
	exit(EXIT_FAILURE);
}
