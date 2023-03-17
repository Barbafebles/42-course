/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:44:56 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/15 16:49:24 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c) // la funcion devuelve el caracter en mayuscula
{
	if (c >= 'a' && c <= 'z') // si el caracter esta entre a y z
		return (c - 32); // devuelve el caracter en mayuscula
	return (c); // si no devuelve el mismo caracter
}

/* int main() 
{ int c = 'a'; 
printf("%c", toupper(c)); 
return (0); } */
