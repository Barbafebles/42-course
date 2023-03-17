/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:37:06 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/15 09:51:45 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c) // la funcion devuelve 1 si el caracter es alfanumerico
{
	if (c >= 0 && c <= 127) // si el caracter esta entre A y Z o entre a y z o entre 0 y 9
		return (1); // devuelve 1
	return (0); //	si no devuelve 0
}

/*int main()
{
	printf("%d", ft_isascii('a'));
	return (0);
}*/