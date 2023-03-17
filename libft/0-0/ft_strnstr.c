/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:18:06 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/15 21:32:13 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *strnstr(const char *hs, const char *needlen, unsigned long len)
{
    unsigned long i; // contador
    unsigned long j; // contador

    i = 0; // contador empieza en 0
    if (needlen[0] == '\0') // si el string es igual a 0
        return ((char *)hs); // devuelve el puntero a la cadena
    while (hs[i] != '\0' && i < len) // mientras que el string sea distinto de 0 y el contador sea menor que n
    {
        j = 0; // contador empieza en 0
        while (hs[i + j] == needlen[j] && needlen[j] != '\0' && i + j < len) // mientras que el string sea igual al string y el string sea distinto de 0 y el contador sea menor que n
            j++; // el contador aumenta
        if (needlen[j] == '\0') // si el string es igual a 0
            return ((char *)hs + i); // devuelve el puntero a la cadena
        i++; // el contador aumenta
    }
    return (0); // devuelve 0
}

