/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbarafebles <barbarafebles@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:52:18 by bfebles-          #+#    #+#             */
/*   Updated: 2024/10/09 19:21:38 by barbarafebl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned long len)
{
	char			*mem;
	int				i;
	unsigned long	p;

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