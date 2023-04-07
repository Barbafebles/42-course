/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:10:43 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/07 17:04:30 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, unsigned long n)
{
	unsigned long	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
			return ((void *)str + i);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char			str[];
	char			c;
	unsigned long	n;

	str[] = "hola";
	c = 'o';
	n = 4;
	ft_memchr(str, c, n);
	printf("%s\n", str);
	return (0);
}
*/
