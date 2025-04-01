/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:58:57 by bfebles-          #+#    #+#             */
/*   Updated: 2025/04/01 21:01:25 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)

{
	t_game game;

	if (argc != 2)
	{
		printf("Uso: %s <mapa.ber>\n", argv[0]);
		return (1);
	}
	game.mlx = mlx_init(800, 600, "Formula 1", 0);
	if (!game.mlx)
	{
		ft_error("Error al inicializar MLX");
	}
	if (!load_map(argv[1], &game.map))
	{
		ft_error("Error al cargar el mapa");
	}
	print_map(&game);
	load_textures(&game);
	render_map(&game);
	mlx_loop(game.mlx);
	cleanup_images(&game);
	return (0);
}
