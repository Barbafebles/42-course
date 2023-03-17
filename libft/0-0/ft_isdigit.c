/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:47:29 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/15 09:59:15 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int m) // la funcion devuelve 1 si el caracter es alfanumerico 
{
	if (m >= '0' && m <= '9') // si el caracter esta entre el 0 y el 9 
		return (1); // devuelve 1
	return (0); // º si no devuelve 0
}
// La funcion isdigit() devuelve 1 si el caracter es un digito, 0 si no lo es.