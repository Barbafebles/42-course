/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:38:33 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/08 17:39:22 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
int main()
{
	unsigned long count;
	unsigned long size;
	char *text;
	
	count = 5;
	size = sizeof(char);
	text = ft_calloc(count, size);
	printf("%s", text);
	return(0);
}
*/
