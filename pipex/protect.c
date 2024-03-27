/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbarafebles <barbarafebles@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:24:28 by barbarafebl       #+#    #+#             */
/*   Updated: 2024/03/26 19:26:59 by barbarafebl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Funcion para manejar errores
void ft_error(char *e)
{
    perror(e);
    exit(EXIT_FAILURE); // EXIT... constante definida en la biblioteca stdlib.h vale 1 | EXIT_SUCESS vale 0 
}