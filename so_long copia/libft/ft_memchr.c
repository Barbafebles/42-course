/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:10:43 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/10 19:37:00 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	*str;
	char	c;
	size_t	n;

	str = "paco estaba en la cocina";
	c = 'o';
	n = ft_strlen(str);
	printf("%s\n", ft_memchr(str, c, n));
	return (0);
}
*/
