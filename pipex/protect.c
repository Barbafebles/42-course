/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbafebles <barbafebles@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:24:28 by barbarafebl       #+#    #+#             */
/*   Updated: 2024/04/16 17:48:45 by barbafebles      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Funcion para manejar errores
void ft_error(char *e)
{
    perror(e);
    exit(EXIT_FAILURE); // EXIT... constante definida en la biblioteca stdlib.h vale 1 | EXIT_SUCESS vale 0 
}

