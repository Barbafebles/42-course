/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:33:01 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/15 21:44:02 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int atoi(const char *str)
{
    int i; // contador
    int j; // contador
    int k; // contador

    i = 0; // contador empieza en 0
    j = 0; // contador empieza en 0
    k = 1; // contador empieza en 1
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r') // mientras que el string sea igual a un espacio o tabulacion o salto de linea o tabulacion vertical o tabulacion horizontal o retorno de carro
        i++; // el contador aumenta
    if (str[i] == '-') // si el string es igual a -
    {
        k = -1; // k es igual a -1
        i++; // el contador aumenta
    }
    else if (str[i] == '+') // si el string es igual a +
        i++; // el contador aumenta
    while (str[i] >= '0' && str[i] <= '9') // mientras que el string sea mayor o igual que 0 y el string sea menor o igual que 9
    {
        j = j * 10 + (str[i] - '0'); // j es igual a j por 10 mas el string menos 0
        i++; // el contador aumenta
    }
    return (j * k); // devuelve j por k
}
