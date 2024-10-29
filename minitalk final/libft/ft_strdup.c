/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:58:48 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/07 11:58:47 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i] != '\0')
		i++;
	ptr = (char *)malloc(i + 1);
	if (ptr == 0)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
int main()
{
	char *str = "hola mundo";
	char *p;

	p = ft_strdup(str);
	printf("La cadena original muestra: %s\n", str);
	printf("La cadena duplicada muestra: %s\n", p);
	return (0);
}
*/