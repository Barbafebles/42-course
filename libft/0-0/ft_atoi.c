/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:32:57 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/22 16:20:48 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str) // esta funcion convierte un string en un int
{
	int	i; // i es un contador
	int	j; // j es el numero que se va a devolver
	int	k; // k es el signo del numero

	i = 0; // inicializamos el contador a 0
	j = 0; // inicializamos el numero a 0
	k = 1; // inicializamos el signo a 1
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' // mientras el caracter sea un espacio, tabulacion, nueva linea, vertical tab o retorno
		|| str[i] == '\f' || str[i] == '\r') // o un salto de pagina o un retorno de carro
		i++; // incrementamos el contador
	if (str[i] == '-') // si el caracter es un -
		k = -1; // el signo es -1 (negativo) 
	if (str[i] == '-' || str[i] == '+') // si el caracter es un - o un + 
		i++; // incrementamos el contador
	while (str[i] && str[i] >= '0' && str[i] <= '9') // mientras el caracter sea un numero entre 0 y 9 
	{
		j = j * 10 + (str[i] - 48); // el numero es igual a el numero por 10 mas el caracter menos 48 para que sea un numero entre 0 y 9 
		i++; // incrementamos el contador
	}
	return (j * k); // devolvemos el numero por el signo para que sea positivo o negativo 
}
