#include "../so_long.h"

void ft_error(const char *msg)
{
    if (msg)
    {
        perror(msg);
    }
    perror("Error");
    exit(EXIT_FAILURE);
}