#include "so_long.h"

int load_map(const char *filename, t_game *game)
{
    size_t len;
    len = ft_strlen(filename);
    // en el .ber tengo que agregar el mapa .ber
    if (len < 4 || ft_strcmp(filename + len - 4, "Maps/mapa1.ber") != 0)
    {
        printf("error\nEl archivo no tiene la extension .ber\n");
        return (0);
    }
    char *line = NULL;
    size_t cap = 0;
    game->height = 0;
    game->map = NULL;
    ssize_t n;
    while ((n = getline(&line, &cap, fdopen(fd, "r"))) != -1) {
        if (n > 0 && line[n-1] == '\n') line[n-1] = '\0';
        if (game->height == 0) {
            game->width = ft_strlen(line);
            if (game->width == 0) {
                ft_error(stderr, "Error\nMapa vacío o línea vacía\n");
                free(line);
                return (0);
            }
        } else {
            if ((int)ft_strlen(line) != game->width) {
                ft_error(stderr, "Error\nEl mapa no es rectangular\n");
                free(line);
                return (0);
            }
        }
        game->map = realloc(game->map, sizeof(char*) * (game->height + 1));
        game->map[game->height] = line;
        line = NULL; cap = 0;
        game->height++;
    }
    close(fd);
    return (1);
}