/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:56:50 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/01 20:12:48 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Lee cada línea del mapa desde el descriptor de archivo y la almacena en map->grid.
// Si falla la lectura de alguna línea, libera las líneas ya leídas y retorna 0.
int	load_map_lines(int fd, t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		map->grid[i] = read_line(fd);
		if (!map->grid[i])
		{
			while (i > 0)
				free(map->grid[--i]);
			free(map->grid);
			return (0);
		}
		i++;
	}
	map->grid[i] = NULL;
	return (1);
}

// Inicializa el mapa contando las líneas del archivo y reservando memoria para el grid.
int	init_map(t_map *map, char *filename)
{
	map->height = count_lines(filename);
	if (map->height == 0)
		return (0);
	map->grid = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (0);
	return (1);
}

// Abre el archivo del mapa en modo lectura.
// Si ocurre un error, se muestra un mensaje de error.
int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error al abrir el archivo del mapa");
	return (fd);
}

// Carga el mapa completo:
// Abre el archivo, inicializa la estructura y lee línea a línea el contenido.
// Finalmente, establece el ancho del mapa basado en la primera línea.
int	load_map(char *filename, t_map *map)
{
	int	fd;

	fd = open_map_file(filename);
	if (fd < 0)
		return (0);
	if (!init_map(map, filename))
	{
		close(fd);
		return (0);
	}
	if (!load_map_lines(fd, map))
	{
		close(fd);
		return (0);
	}
	if (map->height > 0)
		map->width = ft_strlen(map->grid[0]);
	else
		map->width = 0;
	close(fd);
	return (1);
}
// Cuenta la cantidad de líneas en el archivo del mapa leyendo bloques de datos.
// Cada salto de línea incrementa el contador.
size_t	count_lines(char *filename)
{
	int		fd;
	char	buffer[4096];
	ssize_t	bytes_read;
	size_t	count;
	ssize_t	i;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
				count++;
			i++;
		}
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	if (bytes_read > 0 && buffer[bytes_read - 1] != '\n')
		count++;
	close(fd);
	return (count);
}

// Lee una línea del archivo utilizando un buffer y retorna una cadena duplicada.
// Si encuentra un salto de línea, marca el final de la línea y ajusta la posición del descriptor.
char	*read_line(int fd)
{
	char	buffer[4096];
	char	*line;
	ssize_t	bytes_read;
	ssize_t	i;
	size_t	start;

	line = NULL;
	start = 0;
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read <= 0)
		return (NULL);
	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			line = ft_strdup(&buffer[start]);
			lseek(fd, -(bytes_read - i - 1), SEEK_CUR);
			return (line);
		}
		i++;
	}
	line = ft_strdup(buffer);
	return (line);
}
// Libera la memoria reservada para el mapa, incluyendo cada línea almacenada.
void	free_map(t_map *map)
{
	size_t	i;

	if (map->grid)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
}
