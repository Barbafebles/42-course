/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:37:07 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/10 12:29:54 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	int		i;
	char	*src;
	char	chr;

	i = ft_strlen(str);
	src = (char *)str;
	chr = (char)character;
	while (i >= 0)
	{
		if (chr == src[i])
			return (&src[i]);
		i--;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[];
	char	c;

	str[] = "Comer un camaleon";
	c = 'o';
	printf("Este es el último carácter de la str: %s\n", ft_strrchr (str, c));
	return (0);
}
*/