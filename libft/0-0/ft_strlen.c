/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:07:12 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/14 21:32:08 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(const char *s) // esto es un unsigned int porque no puede ser negativo
{
	unsigned int	m; // esto es un unsigned int porque no puede ser negativo

	m = 0; //esto hace que el contador empiece en 0
	while (s[m] != '\0') // mientras que el string sea distinto de 0
	{
		m++; // el contador aumenta
	}
	return (m); // devuelve el contador
}
