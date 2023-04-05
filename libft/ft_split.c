/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:50:18 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/05 19:02:08 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	cw;

	i = 0;
	cw = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && i != 0 && s[i - 1] != c)
			cw++;
		if (s[i] != c && s[i + 1] == '\0')
			cw++;
		i++;
	}
	return (cw);
}

static char	**ft_free(char **mem, size_t p_mem)
{
	while (p_mem > 0)
		free(mem[--p_mem]);
	free(mem);
	return (NULL);
}

static char	**ft_allocate(char **mem, char const *s, char c)
{
	size_t	p_mem;
	size_t	len_w;

	p_mem = 0;
	while (*s != '\0')
	{
		len_w = 0;
		while (*s != '\0' && *s == c)
			++s;
		while (*s != '\0' && *s != c)
		{
			++len_w;
			++s;
		}
		if (*s == c || (*(s - 1) != c && *s == '\0'))
		{
			mem[p_mem] = ft_substr(s - len_w, 0, len_w);
			if (!mem[p_mem])
				return (ft_free(mem, p_mem));
			++p_mem;
		}
	}
	return (mem);
}

char	**ft_split(char const *s, char c)
{
	char	**mem;

	if (!s)
		return (NULL);
	mem = ft_calloc((ft_countwords(s, c) + 1), sizeof(char *));
	if (!mem)
		return (NULL);
	mem = ft_allocate(mem, s, c);
	return (mem);
}
/*
int	main(void)
{
	int		i;
	char	**mem;

	printf("El numero de palabras es: %zu\n", ft_countwords("Hola*que*tal",
				'*'));
	mem = ft_split("Hola**que*tal*", '*');
	i = 0;
	while (mem[i] != NULL)
	{
		printf("%s\n", mem[i]);
		i++;
	}
	i = 0;
	while (mem[i])
	{
		free(mem[i++]);
	}
	free(mem);
	return (0);
}
*/
