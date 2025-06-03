/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:43:00 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/07 17:05:50 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_first(char const *s1, char const *set)
{
	int	j;
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i] != '\0' && set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				j = 0;
				i++;
			}
			if (s1[i] != set[j])
				j++;
		}
		return (i);
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("Resultado: %d\n", ft_pene("cbaHolacb", "abc") - 1);
	return (0);
}
*/

int	ft_last(char const *s1, char const *set)
{
	int	j;
	int	i;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		j = 0;
		while (set[j] != '\0' && i > 0)
		{
			if (s1[i] == set[j])
			{
				j = 0;
				i--;
			}
			if (s1[i] != set[j])
				j++;
		}
		return (i);
	}
	return (0);
}
/*
int	main(void)
{
	char	*s1;
	char	*set;

	s1 = "cbaHolacb";
	set = "abc";
	printf("Resultado: %d\n", ft_last(s1, set));
	return (0);
}
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	int		last;
	int		start;
	char	*punt;

	if (!s1 || !set)
		return (0);
	last = ft_last(s1, set);
	start = ft_first(s1, set);
	punt = ft_substr(s1, start, last - start + 1);
	return (punt);
}
/*
int	main(void)
{
	char	*s1;
	char	*set;
	char	*result;

	s1 = "cbaHolacb";
	set = "abc";
	result = ft_strtrim(s1, set);
	printf("%s", result);
	return (0);
}
*/
