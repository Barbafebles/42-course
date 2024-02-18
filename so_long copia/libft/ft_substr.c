/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:52:18 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/10 13:24:35 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	int		i;
	size_t	p;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		mem = ft_calloc(1, 1);
		return (mem);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	mem = ft_calloc(len + 1, sizeof(char));
	if (!mem)
		return (0);
	i = 0;
	p = start;
	while (s[p] != '\0' && p < (len + start))
	{
		mem[i] = s[p];
		i++;
		p++;
	}
	return (mem);
}
/*
int	main(void)
{
	char			*s;
	unsigned int	start;
	size_t			len;
	char			*mem;

	s = "Hello World";
	start = 6;
	len = 5;
	mem = ft_substr(s, start, len);
	printf("%s", mem);
	return (0);
}
*/