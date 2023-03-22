/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:37:08 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/22 16:21:41 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_bzero(void *s, unsigned long n) // esta funcion pone a 0 los n primeros bytes del area de memoria apuntada por s
{
	ft_memset(s, 0, n); // llamamos a la funcion ft_memset con los parametros s, 0 y n para que ponga a 0 los n primeros bytes del area de memoria apuntada por s
}

/*int main()
{
	char	str[50];

	str[50] = "This is string.h library function";
	ft_bzero(str, 7);
	printf("%s", str);
	return (0);
}
*/
