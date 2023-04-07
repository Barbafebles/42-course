/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:37:08 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/06 11:25:37 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, unsigned long n)
{
	ft_memset(s, 0, n);
}
/*
int	main(void)
{
	int		i;

	i = 0;
	char str[6] = "Paco";
	ft_bzero(str, 3);
	printf("Este es el contenido de la str %s\n", str);
	while (i < 6)
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
*/