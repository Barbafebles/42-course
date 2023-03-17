/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:31:35 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/15 10:01:47 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, unsigned int len) // la funcion devuelve un puntero a la memoria de destino
{
	unsigned int	i; // variable i de tipo entero sin signo negativo 

	if (!dst && !src) // si dst y src son nulos
		return (0); // devuelve 0
	i = 0; // inicializo i a 0
	if (dst < src) // si dst es menor que src
	{
		while (i < len) // mientras i sea menor que len
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i]; // copia el valor de src en dst
			i++; // incrementa i
		}
	}
	else // si no
	{
		while (len > 0) // mientras len sea mayor que 0
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1]; // copia el valor de src en dst
			len--; // decrementa len
		}
	}
	return (dst); // devuelve dst
}
