/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:26:54 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/20 10:07:40 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *hs, const char *needlen, unsigned long len)
{
	unsigned long	i;
	unsigned long	j;

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
