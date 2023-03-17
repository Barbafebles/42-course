/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:01:15 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/15 09:58:00 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, unsigned int n) // copia n bytes de src a dst
{
	unsigned int	i; // variable para iterar

	if (!dst && !src) // si dst y src son nulos
		return (0); // devuelve 0
	i = 0; //`inicializo i a 0
	while (i < n) // mientras i sea menor que n
	{
		((char *)dst)[i] = ((char *)src)[i]; // copia el valor de src en dst
		i++; // incrementa i
	}
	return (dst); // devuelve dst
}

/*#include <stdio.h>
int main (void)
{
    char str1[50] = "Hola";
    char str2[50] = "Adios";
    unsigned long n = 5;

    printf("%s", memcpy(str1, str2, n));
    return (0);
}*/
 // la funcion memcpy lo que hace es copiar n bytes de src a dst y devuelve dst