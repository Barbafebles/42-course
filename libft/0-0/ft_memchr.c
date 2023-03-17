/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:14:42 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/16 15:33:54 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *memchr(const void *str, int c, unsigned long n)
{
    unsigned long i; // contador

    i = 0; // contador empieza en 0
    while (i < n) // mientras que el contador sea menor que n
    {
        if (((unsigned char *)str)[i] == (unsigned char)c) // si el string es igual al caracter
            return ((void *)str + i); // devuelve el puntero a la cadena
        i++; // el contador aumenta
    }
    return (0); // devuelve 0
}
