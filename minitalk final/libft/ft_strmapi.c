/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 08:33:15 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/28 10:48:13 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char to_upper(unsigned int i, char c) 
{
    return toupper(c);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	length;
	char			*res;

	if (!s)
		return (0);
	length = ft_strlen(s);
	res = malloc(length * sizeof(char) + 1);
	if (!res)
		return (0);
	i = 0;
	while (i < length)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>
int main() 
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
    return 0;
}*/