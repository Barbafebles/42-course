/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbarafebles <barbarafebles@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:26:54 by bfebles-          #+#    #+#             */
/*   Updated: 2024/10/09 19:21:15 by barbarafebl      ###   ########.fr       */
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