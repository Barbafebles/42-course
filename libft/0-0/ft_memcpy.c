/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:01:15 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/25 13:46:23 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	unsigned int	i;

	if (!dst && !src)
		return (0);
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

int main (void)
{
	char			str1[50];
	char			str2[50];
	unsigned long	n;

    str1[50] = "Hola";
    str2[50] = "Adios";
    n = 3;
    printf("%s", ft_memcpy(str1, str2, n));
    return (0);
}
*/
