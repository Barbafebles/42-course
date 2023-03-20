/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:37:08 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/20 11:57:29 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, unsigned long n)
{
	unsigned long	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char) '\0';
		i++;
	}
}

/*int main()
{
	char str[50] = "esta es una string.h de esta libreria";
	ft_bzero(str, 7);
	printf("%s", str);
	return (0);
}
*/