/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:00:58 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/15 21:01:17 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *strchr(const char *s, int c)
{
    while (*s != (char)c) // mientras el caracter no sea igual al caracter c
        if (!*s++) // si no hay mas caracteres
            return (0); // devolvemos 0
    return ((char *)s); // devolvemos el puntero a la cadena
}

/*s: Un puntero a una cadena de caracteres en la que se buscará el carácter.
c: El carácter que se buscará en la cadena de caracteres.
El valor devuelto por la función es un puntero al primer carácter encontrado en la cadena 
de caracteres s que sea igual al carácter c. Si el carácter c no se encuentra en la cadena de 
caracteres s, la función devuelve un puntero nulo (NULL).

Es importante tener en cuenta que la función strchr trabaja con caracteres de tipo char, 
pero el parámetro c se pasa como un entero (int). Esto se debe a que el tipo char se convierte implícitamente a int en las llamadas a funciones en C.*/