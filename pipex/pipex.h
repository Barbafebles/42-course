/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbafebles <barbafebles@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:49:17 by barbarafebl       #+#    #+#             */
/*   Updated: 2024/04/30 11:28:05 by barbafebles      ###   ########.fr       */
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
void exec_cmd2(int *pipefd, char **cmd, char **envp);
void exec_comd1(int *pipefd, char **cmd, char **envp);
void parse(int argc, char *argv[], char **cmd1, char **cmd2, char **infile, char **outfile);
int ft_open(const char *file, int flags);
int ft_read(int fd, char *buffer, size_t buffer_size);
void ft_error(char *e);


#endif
