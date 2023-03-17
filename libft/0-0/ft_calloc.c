/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:44:55 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/15 21:46:22 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *calloc(unsigned long num, unsigned long size)
{
    unsigned long i; // contador
    void *ptr; // puntero

    i = 0; // contador empieza en 0
    ptr = malloc(num * size); // puntero es igual a malloc de num * size
    if (ptr == 0) // si el puntero es igual a 0
        return (0); // devuelve 0
    while (i < num * size) // mientras que el contador sea menor que num * size
    {
        ((unsigned char *)ptr)[i] = 0; // el puntero es igual a 0
        i++; // el contador aumenta
    }
    return (ptr); // devuelve el puntero
}
