/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:38:33 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/22 16:25:34 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(unsigned long num, unsigned long size) // esta funcion reserva memoria para un array de num elementos de size bytes cada uno y lo inicializa a 0
{
	unsigned long	i; // i es un contador
	void			*ptr; // ptr es un puntero a void lo necesitamos para poder devolver un puntero a cualquier tipo de dato

	i = 0; // inicializamos el contador a 0
	ptr = malloc(num * size); // reservamos memoria para un array de num elementos de size bytes cada uno y lo guardamos en ptr
	if (ptr == 0) // si ptr es 0
		return (0); // devolvemos 0
	while (i < num * size) // mientras i sea menor que num por size 
	{
		((unsigned char *)ptr)[i] = 0; // el puntero a char apuntado por ptr en la posicion i es igual a 0
		i++; // incrementamos el contador
	}
	return (ptr); // devolvemos ptr
}
