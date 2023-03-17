/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:24:48 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/15 16:02:52 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long ft_strlcat(char *dest, const char *src, unsigned long size) // copia n bytes de src a dst
{
    unsigned long i; // i es el contador de bytes
    unsigned long j; // j es el contador de caracteres
    unsigned long len; // len es el contador de caracteres

    i = 0; // inicializamos i a 0
    j = 0; // inicializamos j a 0
    len = 0; // inicializamos len a 0
    while (dest[i] != '\0') // mientras no lleguemos al final de la cadena
        i++; // sumamos 1 a i
    while (src[len] != '\0') // mientras no lleguemos al final de la cadena
        len++; // sumamos 1 a len
    if (size <= i) // si n es 0
        len += size; // devolvemos len
    else // mientras i sea menor que n - 1 y no lleguemos al final de la cadena
        len += i;  // sumamos 1 a i
    while (src[j] != '\0' && i + 1 < size) // mientras i sea menor que n - 1 y no lleguemos al final de la cadena
    {
        dest[i] = src[j]; // copiamos el caracter de src en dst
        i++; // sumamos 1 a i
        j++; // sumamos 1 a j
    }
    dest[i] = '\0'; // añadimos el caracter nulo al final de la cadena
    return (len); // devolvemos len 
}

/* ************************************************************************** */

unsigned long ft_strlcat(char *dest, const char *src, unsigned long size)  
{
    unsigned long i;
    unsigned long j; 
    unsigned long len;
    
    i = 0;
    j = 0; 
    len = 0;
    j = ft_strlen(dest);
    len = ft_strlen(src);
    if (size <= j)
        len += size;
    else
        len += j;
    while (src[i] != '\0' && j + 1 < size)
    {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (len);
}

/* ************************************************************************** */

unsigned long ft_strlcat(char *dest, const char *src, unsigned long size)
{
    unsigned long i; 
    unsigned long j;
    unsigned long len;

    i = 0;
    j = 0;
    len = 0;
    while (dest[i] != '\0')
        i++;
    while (src[len] != '\0')
        len++;
    if (size <= i)
        len += size;
    else
        len += i;
    while (src[j] != '\0' && i + 1 < size)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (len);
}