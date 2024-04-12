/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbarafebles <barbarafebles@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:49:17 by barbarafebl       #+#    #+#             */
/*   Updated: 2024/04/12 16:37:17 by barbarafebl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
#include <fcntl.h> // para open
#include <unistd.h> // para close, read, write, acces, dup, dup2, execve, fork, pipe, unlink
#include <stdio.h> // para perror
#include <stdlib.h> // para malloc, free, exit
#include <sys/wait.h> // para wait, waitpid
#include <errno.h> //errno 
#include "../libft/libft.h"
#include <string.h> //strerror


/*  pruebas    */
int ft_open(const char *file, int flags);
int ft_read(int fd, char *buffer, size_t buffer_size);
void ft_error(char *e);


#endif
