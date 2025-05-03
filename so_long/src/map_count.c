/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:38:24 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/02 21:38:26 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	process_buffer(char *buf, ssize_t n, size_t *lines, char *last)
{
	ssize_t	i;

	i = 0;
	while (i < n)
	{
		if (buf[i] == '\n')
			(*lines)++;
		i++;
	}
	*last = buf[n - 1];
}

size_t	count_lines(char *filename)
{
	int		fd;
	char	buf[4096];
	size_t	lines;
	char	last;
	ssize_t	n;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	lines = 0;
	last = '\0';
	n = read(fd, buf, sizeof(buf));
	while (n > 0)
	{
		process_buffer(buf, n, &lines, &last);
		n = read(fd, buf, sizeof(buf));
	}
	close(fd);
	if (last != '\n')
		return (lines + 1);
	return (lines);
}
