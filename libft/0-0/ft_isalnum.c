/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:57:49 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/15 09:50:35 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c) // la funcion devuelve 1 si el caracter es alfanumerico
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0'
			&& c <= '9')) // si el caracter esta entre A y Z o entre a y z o entre 0 y 9
		return (1); // devuelve 1
	return (0); // si no devuelve 0
}

/* #include <stdio.h>
int	main(void)
{
    printf("%d", ft_isalnum('a'));
    return (0);
}  */