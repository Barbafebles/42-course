/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:24:48 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/10 12:31:01 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if ((!dest || !src) && size == 0)
		return (0);
	i = 0;
	j = 0;
	len = 0;
	j = ft_strlen(dest);
	len = ft_strlen(src);
	if (size <= j)
		len += size;
	else
		len += j;
	while (src[i] != '\0' && j + 1 < size)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (len);
}
/*
int	main(void)
{
	char	dest[20];
	char	src[20];
	size_t	size;
	size_t	result;

	dest[20] = "hola";
	src[20] = "adios";
	size = 20;
	result = ft_strlcat(dest, src, size);
	printf("%lu", result);
	return (0);
}
*/