/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:48:37 by bfebles-          #+#    #+#             */
/*   Updated: 2023/08/24 18:25:08 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(char c)
{
	int	counter;

	counter = 0;
	counter += write(1, &c, 1);
	return (counter);
}

/*
int	main(void)
{
    char c;

    c = 'A';
    //int num_chars = ft_putchar_pf(c);
    if(c == 'A')
    {
        printf("\nImpresion: '%c'. Número de caracteres impresos: %d\n", c, 1);
    }
    return(0);
}
*/
