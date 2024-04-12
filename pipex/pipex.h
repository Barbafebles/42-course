/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbafebles <barbafebles@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:49:17 by barbarafebl       #+#    #+#             */
/*   Updated: 2024/04/12 15:24:55 by barbafebles      ###   ########.fr       */
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
# include "/home/barbafebles/Desktop/42-course/pipex/libft"
#include <string.h> //strerror


/*  pruebas    */
int ft_open(const char *file, int flags);
int ft_read(int fd, char *buffer, size_t buffer_size);
void ft_error(char *e);


#endif
