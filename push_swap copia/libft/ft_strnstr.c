/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:26:54 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/06 18:01:39 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *hs, const char *needlen, unsigned long len)
{
	unsigned long	i;
	unsigned long	j;

	if ((!hs || !needlen) && len == 0)
		return (0);
	i = 0;
	if (needlen[0] == '\0')
		return ((char *)hs);
	while (hs[i] != '\0' && i < len)
	{
		j = 0;
		while (hs[i + j] == needlen[j] && needlen[j] != '\0' && i + j < len)
			j++;
		if (needlen[j] == '\0')
			return ((char *)hs + i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main ()
{
	char hs[] = "hola, paco";
	char needlen[] = "paco";
	unsigned long len = 10;

	printf("La cadena encontrada es: %s\n", ft_strnstr(hs, needlen, len));
	return (0);
}
*/