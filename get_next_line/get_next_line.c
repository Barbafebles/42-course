/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbarafebles <barbarafebles@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:10:32 by bfebles-          #+#    #+#             */
/*   Updated: 2023/09/12 12:00:50 by barbarafebl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		++i;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_line(int fd, char *rest)
{
	int		bytes_read;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!(ft_strchr(rest, '\n')) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(rest);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		rest = ft_strjoin(rest, buffer);
	}
	free(buffer);
	return (rest);
}

char	*newrest(char *rest)
{
	int		i;
	int		k;
	char	*rest_caract;

	i = 0;
	while (rest[i] != '\0' && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	rest_caract = malloc(sizeof(char) * (ft_strlen(rest) - i + 1));
	if (!rest_caract)
		return (NULL);
	k = 0;
	++i;
	while (rest[i])
		rest_caract[k++] = rest[i++];
	rest_caract[k] = '\0';
	free(rest);
	return (rest_caract);
}

char	*get_next_line(int fd)

{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = newrest(str);
	return (line);
}


int	main(void)
{
	clock_t	start, end;
	double	cpu_time_used;
	char	fd;
	char	*line;

	start = clock();
	fd = open("prueba.txt", O_RDWR);
	if (fd == -1)
		return (0);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
	}
	close(fd);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("El tiempo de ejecucion: %f segundos\n", cpu_time_used);
	return (0);
}

/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("prueba.txt", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf("La linea: %s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/
