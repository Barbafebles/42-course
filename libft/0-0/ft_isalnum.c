/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:57:49 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/22 16:25:54 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0'
			&& c <= '9')) // si el caracter es una letra mayuscula o minuscula o un numero
		return (1); // devolvemos 1
	return (0); // si no devolvemos 0
}

/* #include <stdio.h>
int	main(void)
{
    printf("%d", ft_isalnum('a'));
    return (0);
}  */