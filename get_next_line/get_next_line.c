/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:36:20 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/13 19:08:21 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] != 10 && str[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != 10 && str[i] != '\0')
	{
		line[i] = str[i];
		++i;
	}
	line[i] = '\0';
	return (line);
}
/*
int	main(void)
{
    printf("La primera linea es: %s\n",
		get_line("A ver si funciona esto que acabo de hacer"));
	return(0);
}
*/

char	*read_line(int fd, char *buffer)
{
	int		bytes_read;
	char	*temp;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	return (buffer);
}

/*
int	main(void)
{
	char	*temp;

	temp = read_line();
	if (temp != 0) 
	{
		printf("La cadena leída es: %s\n", temp);
		free(temp);
	} else {
		printf("No se pudo leer una línea.\n");
	}
	return (0);
}
*/

char	*get_next_line(int fd)

{
	char	*str;
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	char	*line;

	if (fd <= 0 && BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
		str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	line = NULL;
	while (!line && (temp = read_line(fd, buffer)))
	{
		str = ft_strjoin(str, temp);
		free(temp);
		line = get_line(str);
	}
	temp = ft_strdup(str + ft_strlen(line) + 1);
	free(str);
	str = temp;
	return (line);
}
