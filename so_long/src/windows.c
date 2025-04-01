#include "../so_long.h"

/*
int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Uso: %s <ancho> <alto>\n", argv[0]);
        return 1;
    }
    
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    
    mlx_t *mlx = mlx_init(width, height, "Formula 1", 0);
    if (!mlx) {
        return 1;
    }
    
    printf("W:%d\n", width);
    printf("H:%d\n", height);
    
    mlx_loop(mlx); // mantiene la ventana abierta
    mlx_terminate(mlx);
    
    return 0;
}
*/

int main(int argc, char **argv)

{
    t_game game;

    if (argc != 2) 
    {
        printf("Uso: %s <mapa.ber>\n", argv[0]);
        return 1;
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
    return 0;
}