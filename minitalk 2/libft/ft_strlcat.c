/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbarafebles <barbarafebles@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:24:48 by bfebles-          #+#    #+#             */
/*   Updated: 2024/10/09 19:20:48 by barbarafebl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcat(char *dest, const char *src, unsigned long size)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	len;

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
