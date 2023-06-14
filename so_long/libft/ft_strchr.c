/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:00:58 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/10 16:24:31 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

/*
#include <stdio.h>

int	main(void)
{
	char	s[];
	char	c;

	s[] = "hola";
	c = 'a';
	printf("El caracter existe: %s\n", ft_strchr(s, c));
	return (0);
}
*/
