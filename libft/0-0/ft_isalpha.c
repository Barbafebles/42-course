/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:51:35 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/22 16:29:00 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c) // esta funcion comprueba si el caracter c es una letra mayuscula o minuscula
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90)) // si el caracter es una letra mayuscula o minuscula
		return (1); // devolvemos 1
	return (0); // si no devolvemos 0
}

/* int main()
{
	printf("%d", ft_isalpha('a'));
	return (0);
}*/