/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:01:15 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/10 19:39:25 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[6] = "hola";
	char	dst[6] ="adios";

	ft_memcpy(dst, src, 6);
	dst[5] = '\0';
	printf("Este es el dst: %s\n", dst);
	return (0);
}
*/
