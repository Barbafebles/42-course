/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbarafebles <barbarafebles@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:42:35 by barbarafebl       #+#    #+#             */
/*   Updated: 2024/03/26 17:16:41 by barbarafebl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Funcion open manejando errores
int ft_open(const char *file, int flags)
{
    int fd;

    fd = open(file, flags);
    if(fd == -1)
        ft_error("error");
    return fd;
}

int ft_read(int fd, char *buffer, size_t buffer_size)
{
    ssize_t bytes_read;
    
    bytes_read = read(fd, buffer, buffer_size);
    if(bytes_read == -1)
        ft_error("error reading file");
    return (bytes_read);
}
//Funcion para manejar errores
void ft_error(char *e)
{
    perror(e);
    exit(EXIT_FAILURE); // EXIT... constante definida en la biblioteca stdlib.h vale 1 | EXIT_SUCESS vale 0 
}


