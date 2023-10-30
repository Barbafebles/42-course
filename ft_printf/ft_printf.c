/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:51:10 by bfebles-          #+#    #+#             */
/*   Updated: 2023/05/24 12:57:05 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char *format, va_list arguments)
{
	int	counter;

	counter = 0;
	if (*format == 'c')
		counter += ft_putchar_pf(va_arg(arguments, int));
	else if (*format == 's')
		counter += ft_putstr_pf(va_arg(arguments, char *));
	else if (*format == 'p')
		counter += ft_putptr_pf(va_arg(arguments, unsigned long long));
	else if (*format == 'x' || *format == 'X')
		counter += ft_puthexa_pf(va_arg(arguments, unsigned int), *format);
	else if (*format == 'd' || *format == 'i')
		counter += ft_putnbr_pf(va_arg(arguments, int));
	else if (*format == 'u')
		counter += ft_putunit_pf(va_arg(arguments, unsigned int));
	else if (*format == '%')
		counter += ft_putchar_pf(*format);
	else
		return (0);
	return (counter);
}

int	ft_printf(char const *format, ...)
{
	int		counter;
	va_list	arguments;

	counter = 0;
	va_start(arguments, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			++format;
			counter += ft_format((char *)format, arguments);
		}
		else
			counter += ft_putchar_pf(*format);
		++format;
	}
	va_end(arguments);
	return (counter);
}
