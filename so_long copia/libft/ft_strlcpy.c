/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:32:02 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/10 12:40:43 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (n == 0)
		return (len);
	while (i < n - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

/*
#include <stdio.h>

int main ()
{
	char	dest[20];
	char	src[20];
	size_t	size;
	size_t	result;

	dest[20] = "hola";
	src[20] = "adios";
	size = 20;
	result = ft_strlcpy(dest, src, size);
	printf("%lu", result);
	return (0);
}
*/