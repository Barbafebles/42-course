/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:07:12 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/05 12:41:54 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(const char *s)
{
	unsigned int	m;

	m = 0;
	while (s[m] != '\0')
	{
		m++;
	}
	return (m);
}
/*
#include <stdio.h>

int main()
{
	char *str;
	unsigned int l;

	str = "hola patata";
	l = ft_strlen(str);
	printf("Esta es la longitud %u de la cadena %s", l, str);
	return 0;
}
*/
// calcula el numero de caracteres de la cadena apuntada por s 