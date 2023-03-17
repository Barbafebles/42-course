/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:47:19 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/15 21:48:37 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *strdup(const char *str)
{
    int i; // contador
    char *ptr; // puntero

    i = 0; // contador empieza en 0
    while (str[i] != '\0') // mientras que el string sea distinto de 0
        i++; // el contador aumenta
    ptr = (char *)malloc(i + 1); // puntero es igual a malloc de i + 1
    if (ptr == 0) // si el puntero es igual a 0
        return (0); // devuelve 0
    i = 0; // contador empieza en 0
    while (str[i] != '\0') // mientras que el string sea distinto de 0
    {
        ptr[i] = str[i]; // el puntero es igual al string
        i++; // el contador aumenta
    }
    ptr[i] = '\0'; // el puntero es igual a 0
    return (ptr); // devuelve el puntero
}
