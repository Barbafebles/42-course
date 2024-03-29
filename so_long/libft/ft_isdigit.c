/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:47:29 by bfebles-          #+#    #+#             */
/*   Updated: 2023/04/10 15:22:39 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int m)
{
	if (m >= '0' && m <= '9')
		return (1);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	int m;
	m = '0';
	printf("%d", ft_isdigit('0'));
	return(0);
}*/