/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:22:18 by bfebles-          #+#    #+#             */
/*   Updated: 2023/05/24 12:27:14 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int n)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
	{
		counter += write(1, "-", 1);
		counter += write(1, "2", 1);
		counter += ft_putnbr_pf(147483648);
	}
	else if (n < 0)
	{
		counter += write(1, "-", 1);
		counter += ft_putnbr_pf(-n);
	}
	else if (n <= 9)
		counter += ft_putchar_pf('0' + n);
	else
	{
		counter += ft_putnbr_pf(n / 10);
		counter += ft_putchar_pf('0' + (n % 10));
	}
	return (counter);
}
