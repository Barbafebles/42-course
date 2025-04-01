#include "../so_long.h"

mlx_image_t *load_xpm_image(mlx_t *mlx, const char *file_path)
{
    xpm_t *xpm = mlx_load_xpm42(file_path);
    if (!xpm)
        ft_error("Error al cargar XPM");

    mlx_texture_t *tex = &xpm->texture;
    mlx_image_t *img = mlx_texture_to_image(mlx, tex);
    if (!img)
    {
        mlx_delete_texture(tex);
        ft_error("Error al convertir textura a imagen");
    }
    mlx_delete_xpm42(xpm);
    return (img);
}

void load_textures(t_game *game)
{
    game->images.asfalto_img = load_xpm_image(game->mlx, "xpm/asfalto.xpm");
    if (!game->images.asfalto_img)
        ft_error("Error al cargar asfalto.xpm");

    game->images.cocheMax_img = load_xpm_image(game->mlx, "xpm/cocheMax.xpm");
    if (!game->images.cocheMax_img)
        ft_error("Error al cargar cocheMax__1_.xpm");

    game->images.casco_img = load_xpm_image(game->mlx, "xpm/cascoMax.xpm");
    if (!game->images.casco_img)
        ft_error("Error al cargar cascoMax.xpm");
}

void render_map(t_game *game)
{
    size_t y = 0;
    size_t x;

    if (!game->map.grid)
        return;

    while (game->map.grid[y])
    {
        x = 0;
        while (game->map.grid[y][x])
        {
            mlx_image_to_window(game->mlx, game->images.asfalto_img,
                                x * TILE_SIZE, y * TILE_SIZE);
            if (game->map.grid[y][x] == '1')
                mlx_image_to_window(game->mlx, game->images.cocheMax_img,
                                    x * TILE_SIZE, y * TILE_SIZE);
            if (game->map.grid[y][x] == 'P')
                mlx_image_to_window(game->mlx, game->images.casco_img,
                                    x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}

void cleanup_images(t_game *game)
{
    if (game->images.asfalto_img)
        mlx_delete_image(game->mlx, game->images.asfalto_img);
    if (game->images.cocheMax_img)
        mlx_delete_image(game->mlx, game->images.cocheMax_img);
    if (game->images.casco_img)
        mlx_delete_image(game->mlx, game->images.casco_img);
}

void print_map(t_game *game)
{
    size_t y = 0;

    printf("Mapa:\n");
    while (game->map.grid[y])
    {
        printf("%s\n", game->map.grid[y]);
        y++;
    }
}
