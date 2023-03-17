/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:09:54 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/16 14:28:59 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int strncmp(const char *str1, const char *str2, unsigned long n)
{
    unsigned long i; // contador

    i = 0; // contador empieza en 0
    while (str1[i] != '\0' && str2[i] != '\0' && i < n) // mientras que el string sea distinto de 0 y el string sea distinto de 0 y el contador sea menor que n
    {
        if (str1[i] != str2[i]) // si el string 1 es distinto del string 2
            return (str1[i] - str2[i]); // devuelve el string 1 menos el string 2
        i++; // el contador aumenta
    }
    return (0); // devuelve 0
}

La función strcmp() compara las dos cadenas de caracteres s1 y s2.  Devuelve un entero
       menor, igual o mayor que cero si se encuentra que s1 es, respectivamente, menor que, igual
       a (concordante), o mayor que s2.

       La función strncmp() es similar, salvo que solamente compara los primeros n caracteres de
       s1.

        Las funciones strcmp() y strncmp() devuelven un entero menor que, igual a, o mayor que
       cero si s1 (o los primeros n bytes en el segundo caso) se encuentra que es, respectiva
       mente, menor que, igual a, o mayor que s2.
