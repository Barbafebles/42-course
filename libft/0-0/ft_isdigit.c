/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:47:29 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/22 16:29:45 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int m) // esta funcion comprueba si el caracter m es un numero 
{
	if (m >= '0' && m <= '9') // si el caracter es un numero
		return (1); // devolvemos 1
	return (0); // si no devolvemos 0
}

/*int main()
{
	int m  '0';
	printf(%d, ft_isdigit(m));
	return (0);
}*/
