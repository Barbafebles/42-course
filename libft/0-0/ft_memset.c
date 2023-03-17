/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:13:48 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/15 10:02:20 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, unsigned int len) // la funcion devuelve un puntero a la memoria que se ha rellenado
{
	unsigned int	i; // variable i de tipo entero sin signo negativo

	i = 0; // 		inicializo i a 0
	while (i < len) // mientras i sea menor que len
	{
		((unsigned char *)b)[i] = (unsigned char)c; // copia el valor de c en b
		i++; // incrementa i
	}
	return (b); // devuelve b
}
