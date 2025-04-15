/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:58:34 by bfebles-          #+#    #+#             */
/*   Updated: 2025/04/15 15:42:28 by bfebles-         ###   ########.fr       */
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
void	check_collectible(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == 'C')
	{
		game->map.grid[y][x] = '0'; // Lo borro del mapa lógico
		game->map.collectable--;    // Disminuye el contador
		printf("¡Casco recogido! Quedan: %d\n", game->map.collectable);

		//si ya no quedan, desbloquear la salida (todavia no he agregado la salida)
	}
}
