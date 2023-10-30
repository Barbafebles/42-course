/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:12:38 by bfebles-          #+#    #+#             */
/*   Updated: 2023/08/24 17:34:21 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_pf(unsigned int hexa, char form)
{
	int	counter;

	counter = 0;
	if (hexa >= 16)
	{
		counter += ft_puthexa_pf(hexa / 16, form);
		counter += ft_puthexa_pf(hexa % 16, form);
	}
	else
	{
		if (hexa <= 9)
			counter += ft_putchar_pf(hexa + 48);
		else
		{
			if (form == 'X')
				counter += ft_putchar_pf(hexa - 10 + 'A');
			else if (form == 'x')
				counter += ft_putchar_pf(hexa - 10 + 'a');
		}
	}
	return (counter);
}

/*
int	main(void)
{
    unsigned int num;
    char form;

    num = 12;
    form = 'X';
	printf("Este es el numero hexa: %X\n", num);
    return(0);
}
*/
