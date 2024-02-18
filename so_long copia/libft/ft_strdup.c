/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:58:48 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/10 16:26:11 by bfebles-         ###   ########.fr       */
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
	ptr = ft_calloc((i + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}

/*
int	main(void)
{
	char	*str;
	char	*p;

	str = "hola mundo";
	p = ft_strdup(str);
	printf("La cadena original muestra: %s\n", str);
	printf("La cadena duplicada muestra: %s\n", p);
	return (0);
}
*/
