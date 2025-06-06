# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 00:00:00 by user              #+#    #+#              #
#    Updated: 2025/05/22 15:13:00 by bfebles-         ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

COMMON_SRC_FILES = \
	input_parsing.c \
	util_parsing.c \
	utils.c \
	stack_utils.c \
	stack_utils2.c \
	stack_utils3.c \
	stack_operations.c \
	stack_rotate_operations.c \
	stack_rotate_operations2.c \
	sorting_algorithms.c \
	sorting_algorithms2.c \
	sorting_algorithms3.c
				 

COMMON_SRCS = $(addprefix $(SRC_DIR)/, $(COMMON_SRC_FILES))
COMMON_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(COMMON_SRCS))

PUSH_SWAP_MAIN_C = $(SRC_DIR)/main.c
SRCS_PUSH_SWAP = $(PUSH_SWAP_MAIN_C) $(COMMON_SRCS)
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

HEADERS = $(INC_DIR)/push_swap.h
INC_FLAGS = -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS_PUSH_SWAP) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS_PUSH_SWAP) $(LIBFT_A) -o $(NAME)
	@echo "\033[0;32m✅ push_swap compilado! ✅\033[0m"

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) # Asegura que OBJ_DIR se cree antes de intentar compilar

clean:
	@make clean -C $(LIBFT_DIR) || true # Limpia también los objetos de libft
	rm -rf $(OBJ_DIR)
	@echo "\033[0;33m🧹 Archivos objeto eliminados 🧹\033[0m"

fclean: clean
	@make fclean -C $(LIBFT_DIR) || true # Limpia también el binario de libft
	rm -f $(NAME)
	@echo "\033[0;33m🧹 Ejecutable y archivos objeto eliminados 🧹\033[0m"

re: fclean all

.PHONY: all clean fclean re
