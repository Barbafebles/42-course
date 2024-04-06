
#include "so_long.h"

// una función que lea el mapa 
char	**ft_readmaps(int fd)
{
	char	line;
	char	strmaps;
	char	map;

	while (1) // verdadero. No para el bucle hasta que se cumpla
	{
		line = get_next_line(fd);
		if (!(ft_strncmp(line, "(null)", ft_strlen(line))));
			break;
		strmaps = ft_strjoin(strmaps, line);
		free(line);
	}
	map = ft_split(strmaps, '\n');
	return (map);
}
// una función que busque al personaje
