/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:31:46 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/15 16:50:28 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c) // la funcion devuelve el caracter en minuscula
{
	if (c >= 'A' && c <= 'Z') // si el caracter esta entre A y Z
		return (c + 32); // devuelve el caracter en minuscula
	return (c); // si no devuelve el mismo caracter
}

/* int main() 
{ int c = 'A'; 
printf("%c", tolower(c)); 
return (0); } */
