/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:58:34 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/02 20:11:10 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(const char *msg)
{
	if (msg)
	{
		perror(msg);
	}
	perror("Error");
	exit(EXIT_FAILURE);
}
void    check_collectible(t_game *game, int x, int y)
{
    int i;
    if (!game || !game->map.grid || !game->images.casco_imgs || !game->mlx)
        return;
    if (game->map.grid[y][x] == 'C')
    {
        i = 0;
        while (i < game->images.num_cascos)
        {
            if (game->images.casco_imgs[i] && 
                game->images.casco_imgs[i]->instances &&
                game->images.casco_imgs[i]->instances[0].x == x * TILE_SIZE &&
                game->images.casco_imgs[i]->instances[0].y == y * TILE_SIZE)
            {
                mlx_delete_image(game->mlx, game->images.casco_imgs[i]);
                game->images.casco_imgs[i] = NULL;
                
                game->map.grid[y][x] = '0';
                game->map.collectable--;
                printf("¡Casco recogido! Quedan: %d\n", game->map.collectable);
                
                if (game->map.collectable == 0)
                {
                    printf("\n¡Has recogido todos los cascos! Dirígete a la salida.\n");
                }
                return;
            }
            i++;
        }
    }
}
