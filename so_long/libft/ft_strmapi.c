/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 08:33:15 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/10 16:34:53 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	to_upper(unsigned int i, char c) 
{
    return (toupper(c));
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	length;
	char	*res;

	if (!s)
		return (0);
	length = ft_strlen(s);
	res = ft_calloc(length + 1, sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (i < length)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	return (res);
}
/*
#include <stdio.h>

int	main(void) 
{
    const char *input = "hola";
    char *output = ft_strmapi(input, to_upper);
    
    if (output) 
	{
        printf("Entrada: %s\n", input);
        printf("Salida: %s\n", output);
        free(output);
    } 
	else 
	{
        printf("Error al aplicar ft_strmapi\n");
    }
    return (0);
}*/