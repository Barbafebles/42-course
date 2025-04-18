/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:03:16 by bfebles-          #+#    #+#             */
/*   Updated: 2025/04/16 20:01:32 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    check_exit(t_game *game, int x, int y)
{
    if (game->map.grid[y][x] == 'E')
    {
        if (game->map.collectable == 0)
        {
            printf("\n¡Felicidades! Has completado el nivel en %d movimientos\n", game->moves);
            mlx_close_window(game->mlx);
        }
        else
            printf("\nNecesitas recoger todos los cascos antes de salir (%d restantes)\n", 
                   game->map.collectable);
    }
}

void    move_player(t_game *game, int dx, int dy)
{
    int new_x = game->player_x + dx;
    int new_y = game->player_y + dy;

    if (new_y >= 0 && new_y < (int)game->map.height
        && new_x >= 0 && new_x < (int)game->map.width
        && (game->map.grid[new_y][new_x] == '0'
            || game->map.grid[new_y][new_x] == 'C'
            || game->map.grid[new_y][new_x] == 'E'))
    {
        char next_pos = game->map.grid[new_y][new_x];

        if (next_pos == 'C')
            check_collectible(game, new_x, new_y);

        game->map.grid[game->player_y][game->player_x] = '0';
        game->map.grid[new_y][new_x] = 'P';

        game->player_x = new_x;
        game->player_y = new_y;

        if (game->images.player_img)
            mlx_delete_image(game->mlx, game->images.player_img);
        game->images.player_img = load_xpm_image(game->mlx, "./xpm/cocheMax.png");
        if (!game->images.player_img)
            ft_error("Error al cargar la imagen del jugador");
        mlx_image_to_window(game->mlx, game->images.player_img,
            new_x * TILE_SIZE, new_y * TILE_SIZE);
        if (next_pos == 'E')
        check_exit(game, new_x, new_y);

        game->moves++;
        printf("Movimientos realizados: %d\n", game->moves);
    }
}

void    key_hook(mlx_key_data_t keydata, void *param)
{
    t_game  *game;

    game = (t_game *)param;
    if (keydata.action == MLX_PRESS)
    {
        if (keydata.key == MLX_KEY_ESCAPE)
            mlx_close_window(game->mlx);
        else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
            move_player(game, 0, -1);
        else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
            move_player(game, 0, 1);
        else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
            move_player(game, -1, 0);
        else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
            move_player(game, 1, 0);
    }
}
