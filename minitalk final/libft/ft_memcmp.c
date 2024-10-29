/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:42:55 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/07 17:04:36 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, unsigned long num)
{
	unsigned long	i;

	i = 0;
	while (i < num)
	{
		if (((unsigned char *)ptr1)[i] != ((unsigned char *)ptr2)[i])
			return (((unsigned char *)ptr1)[i] - ((unsigned char *)ptr2)[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char			str1[];
	char			str2[];
	unsigned long	n;

	str1[] = "hola";
	str2[] = "holb";
	n = 4;
	ft_memcmp(str1, str2, n);
	printf("%d\n", ft_memcmp(str1, str2, n));
	return (0);
}
*/
