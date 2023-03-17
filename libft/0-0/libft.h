/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:05:10 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/14 12:17:54 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <ctype.h>

int				ft_isalpha(int c);
int				ft_isdigit(int arg);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
unsigned int	ft_strlen(const char *s);
void			*ft_memset(void *b, int c, unsigned int len);
void			*ft_memcpy(void *dst, const void *src, unsigned int n);
void			*ft_memmove(void *dst, const void *src, unsigned int len);
unsigned long	ft_strlcpy(char *dst, const char *src, unsigned long n);
#endif