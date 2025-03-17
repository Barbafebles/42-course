/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbarafebles <barbarafebles@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:42:44 by bfebles-          #+#    #+#             */
/*   Updated: 2024/02/17 21:25:56 by barbarafebl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1042
# endif

char	*get_next_line(int fd);
int		ft_strchr(const char *s, int c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *stash, char *buff);
int		ft_strlen(const char *s);

#endif
