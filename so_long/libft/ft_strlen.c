/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:07:12 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/10 12:37:37 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	m;

	m = 0;
	while (s[m] != '\0')
	{
		m++;
	}
	return (m);
}

/*
#include <stdio.h>

int	main(void)
{
	char			*str;
	unsigned int	l;

	str = "hola patata";
	l = ft_strlen(str);
	printf("Esta es la longitud %u de la cadena %s", l, str);
	return (0);
}
*/
