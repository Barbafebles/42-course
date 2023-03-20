/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:05:10 by bfebles-          #+#    #+#             */
/*   Updated: 2023/03/20 10:16:06 by bfebles-         ###   ########.fr       */
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
void			ft_bzero(void *s, unsigned long n);
void			*ft_memcpy(void *dst, const void *src, unsigned int n);
void			*ft_memmove(void *dst, const void *src, unsigned int len);
unsigned long	ft_strlcpy(char *dst, const char *src, unsigned long n);
unsigned long	ft_strlcat(char *dest, const char *src, unsigned long size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *str, int character);
int				ft_strncmp(const char *str1, const char *str2, unsigned long n);
void			*ft_memchr(const void *str, int c, unsigned long n);
int				ft_memcmp(const void *ptr1, const void *ptr2,
					unsigned long num);
char			*ft_strnstr(const char *hs, const char *needlen,
					unsigned long len);
int				ft_atoi(const char *str);
void			*ft_calloc(unsigned long num, unsigned long size);
char			*ft_strdup(const char *str);
#endif
