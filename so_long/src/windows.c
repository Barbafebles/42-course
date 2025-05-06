/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:58:57 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/06 14:13:12 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	setup_game(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		ft_printf("Uso: %s <mapa.ber>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (!load_map(argv[1], &game->map))
		ft_error("Error al cargar el mapa");
	game->mlx = mlx_init(game->map.width * TILE_SIZE, game->map.height
			* TILE_SIZE, "Formula 1", 0);
	if (!game->mlx)
		ft_error("Error al inicializar MLX");
	check_extension(argv[1]);
	validate_map_complete(&game->map);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	setup_game(argc, argv, &game);
	print_map(&game);
	load_textures(&game);
	render_static_map(&game);
	init_player_image(&game);
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);
	cleanup_images(&game);
	free_map(&game.map);
	mlx_terminate(game.mlx);
	return (0);
}
