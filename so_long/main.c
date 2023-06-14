/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 08:46:09 by bfebles-          #+#    #+#             */
/*   Updated: 2023/06/03 18:24:32 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "so_long.h"

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

int	ft_validmap(const char *filename)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		line = malloc(sizeof(char) * BUFFER_SIZE);
		i = get_next_line(fd, line);
		if (i == -1)
			return (0);
		if (i == 0)
			break;
		free(line);
	}
	free(line);
	close(fd);
	return (1);
}

int	main(char arg, char *argv[])
{
	char	**maps;
	int		fd;

	if (arg == 2)
	{
		if (ft_validmap(argv[1]))
		{
			fd = open(argv[1], O_RDONLY);
			maps = ft_readmaps(fd);
			while (*maps != NULL)
			{
				ft_printf("%s\n", *maps);
				maps++;
			}
			close(fd);
		}
		return (0);
	}
	return(0);
}
*/
