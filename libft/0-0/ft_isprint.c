/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:38:51 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/15 09:58:31 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c) // la funcion devuelve 1 si el caracter es alfanumerico 
{
	if (c >= 32 && c <= 126) // si el caracter es un caracter imprimible de la tabla ASCII 
		return (1); // devuelve 1				
	return (0);	// si no devuelve 0	
}
// La funcion isprint() devuelve 1 si el caracter es imprimible, 0 si no lo es.