/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbarafebles <barbarafebles@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:37:07 by bfebles-          #+#    #+#             */
/*   Updated: 2024/10/09 19:21:20 by barbarafebl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	int		i;
	char	*src;
	char	chr;

	i = ft_strlen(str);
	src = (char *)str;
	chr = (char)character;
	while (i >= 0)
	{
		if (chr == src[i])
			return (&src[i]);
		i--;
	}
	return (0);
}