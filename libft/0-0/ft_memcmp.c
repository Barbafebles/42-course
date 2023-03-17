/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:16:36 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/15 21:17:33 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int memcmp(const void *ptr1, const void *ptr2, unsigned long num)
{
    unsigned long i; // contador

    i = 0; // contador empieza en 0
    while (i < num) // mientras que el contador sea menor que n
    {
        if (((unsigned char *)ptr1)[i] != ((unsigned char *)ptr2)[i]) // si el puntero 1 es distinto del puntero 2
            return (((unsigned char *)ptr1)[i] - ((unsigned char *)ptr2)[i]); // devuelve el puntero 1 menos el puntero 2
        i++; // el contador aumenta
    }
    return (0); // devuelve 0
}
