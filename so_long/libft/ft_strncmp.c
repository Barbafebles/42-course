/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:13:20 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/10 12:40:04 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((unsigned char)s1[i] != '\0' || (unsigned char)s2[i] != '\0')
		&& (i < n))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[];
	char	s2[];
	int		result;

	s1[] = "culo g";
	s2[] = "culo c";
	result = ft_strncmp(s1, s2, 6);
	printf("s1: %s, s2: %s, diferencia: %d\n", s1, s2, result);
	return (0);
}
*/