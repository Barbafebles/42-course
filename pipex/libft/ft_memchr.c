/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbarafebles <barbarafebles@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:10:43 by bfebles-          #+#    #+#             */
/*   Updated: 2024/02/18 12:36:53 by barbarafebl      ###   ########.fr       */
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
	char			*str;
	char			c;
	unsigned long	n;
	void	*result;
	

	str = "hola";
	c = 'o';
	n = 4;
	result = ft_memchr(str, c, n);
    if (result != NULL)
    {
        printf("El carácter '%c' se encontró en la posición %ld.\n", c, (unsigned long)(result - (void *)str));
    }
    else
    {
        printf("El carácter '%c' no se encontró en los primeros %ld caracteres.\n", c, n);
    }
	return (0);
}
*/
