#include "so_long.h"

static void close_window(void *param)
{
    t_game *game;
    
    game = (t_game *)param;
    mlx_terminate(game->mlx);
    exit(0);
}

static void init_game(t_game *game)
{
    game->mlx = mlx_init(800, 600, "so_long", true);
    if (!game->mlx)
        exit(1);
    mlx_close_hook(game->mlx, &close_window, game);
    mlx_loop(game->mlx);
}

int main(void)
{
    t_game game;

    init_game(&game);
    return (0);
}
