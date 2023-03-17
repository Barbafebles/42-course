/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:06:55 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/16 10:39:35 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strrchr(const char *str, int character) // 
{
	int i; // contador
	char *src; // puntero
	char chr; // caracter
	
	i = ft_strlen(str); // contador empieza en la longitud del string
	src = (char *)str; // el puntero empieza en el string
	chr = (char )character; // el caracter empieza en el caracter
	while (i >= 0) // mientras que el contador sea mayor o igual que 0
	{ 
			return (&src[i]); // devuelve el puntero mas el contador
			i--; // el contador disminuye
	}
	return (0); // devuelve 0
}

