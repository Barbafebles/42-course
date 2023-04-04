/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:38:33 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/30 18:41:31 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(unsigned long num, unsigned long size)
{
	unsigned long	i;
	void			*ptr;

	i = 0;
	ptr = malloc(num * size);
	if (!ptr)
		return (0);
	while (i < num * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
