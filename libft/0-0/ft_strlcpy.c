/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:32:02 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/15 14:05:08 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_strlcpy(char *dst, const char *src, unsigned long n) // copia n bytes de src a dst	
{
	unsigned int	i; // i es el contador de bytes
	unsigned int	len; // len es el contador de caracteres

	i = 0; // inicializamos i a 0
	len = 0; // inicializamos len a 0
 	while (src[len] != '\0') // mientras no lleguemos al final de la cadena
		len++; // sumamos 1 a len
	if (n == 0) // si n es 0
		return (len); // devolvemos len
 	while (i < n - 1 && src[i] != '\0') // mientras i sea menor que n - 1 y no lleguemos al final de la cadena
	{
		dst[i] = src[i]; // copiamos el caracter de src en dst
		i++; // sumamos 1 a i
	}
	dst[i] = '\0'; // añadimos el caracter nulo al final de la cadena
	return (len); // devolvemos len 
}
