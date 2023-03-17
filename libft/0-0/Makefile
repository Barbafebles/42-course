# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfebles- <bfebles-@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 12:03:12 by bfebles-          #+#    #+#              #
#    Updated: 2023/03/14 11:32:46 by bfebles-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIB = libft.h
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror 
RM = rm -f
AR = ar -rcs
SRCS = ft_isalpha.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_isascii.c ft_isalnum.c ft_memset.c ft_memcpy.c ft_memmove.c ft_strlcpy.c
OBJS = $(SRCS:.c=.o)

all:	$(NAME) 

$(NAME): $(OBJS) $(LIB)
	$(AR) $(NAME) $(OBJS)

%.o:%.c
	$(CC) -c $(CFLAGS) $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
