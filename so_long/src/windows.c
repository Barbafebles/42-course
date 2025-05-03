/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:58:57 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/03 12:24:52 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		window_width;
	int		window_height;

	if (argc != 2)
	{
		printf("Uso: %s <mapa.ber>\n", argv[0]);
		return (1);
	}
	if (!load_map(argv[1], &game.map))
		ft_error("Error al cargar el mapa");
	window_width = game.map.width * TILE_SIZE;
	window_height = game.map.height * TILE_SIZE;
	game.mlx = mlx_init(window_width, window_height, "Formula 1", 0);
	if (!game.mlx)
		ft_error("Error al inicializar MLX");
	check_extension(argv[1]);
	validate_map_complete(&game.map);
	print_map(&game);
	load_textures(&game);
	render_static_map(&game);
	init_player_image(&game);
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
