/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:00:58 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/06 16:28:40 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s[] = "hola";
	char	c = 'a';
	printf("El caracter existe: %s\n", ft_strchr(s, c));
	return (0);
}
*/
