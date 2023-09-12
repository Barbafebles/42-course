/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbarafebles <barbarafebles@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:10:17 by bfebles-          #+#    #+#             */
/*   Updated: 2023/09/12 11:12:21 by barbarafebl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i] != '\0')
		i++;
	ptr = malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *stash, char *buff)
{
	int		i;
	int		j;
	char	*str;

	if (!stash)
	{
		stash = malloc(sizeof(char));
		stash[0] = '\0';
	}
	if (!stash || !buff)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buff) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (stash[++i])
		str[i] = stash[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[i] = '\0';
	free(stash);
	return (str);
}

int	ft_strlen(const char *s)
{
	int	m;

	m = 0;
	while (s[m] != '\0')
		m++;
	return (m);
}
