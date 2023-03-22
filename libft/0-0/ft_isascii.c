/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:37:06 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/22 16:29:28 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c) // esta funcion comprueba si el caracter c es un caracter ascii
{
	if (c >= 0 && c <= 127) // si el caracter es un caracter ascii
		return (1); // devolvemos 1
	return (0); // si no devolvemos 0
}

/*int main()
{
	printf("%d", ft_isascii('a'));
	return (0);
}*/