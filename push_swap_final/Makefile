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

# Directorio de Libft
LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

# Archivos fuente comunes para el proyecto push_swap
COMMON_SRC_FILES = input_parsing.c \
                   stack_utils.c \
                   stack_operations.c \
                   stack_rotate_operations.c \
                   sorting_algorithms.c \
                   utils.c # Nota: Si ft_putstr_fd, ft_isdigit, ft_isspace, etc. están ahora en libft, puedes eliminar utils.c de aquí.

COMMON_SRCS = $(addprefix $(SRC_DIR)/, $(COMMON_SRC_FILES))
COMMON_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(COMMON_SRCS))

# Archivos específicos de push_swap
PUSH_SWAP_MAIN_C = $(SRC_DIR)/main.c
SRCS_PUSH_SWAP = $(PUSH_SWAP_MAIN_C) $(COMMON_SRCS)
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

HEADERS = $(INC_DIR)/push_swap.h
# Incluir el directorio de includes de libft si tienes funciones de libft en tus headers
# (aunque normalmente se incluye directamente en los .c de push_swap si usan funciones de libft)
INC_FLAGS = -I$(INC_DIR) -I$(LIBFT_DIR) # Añade -I$(LIBFT_DIR) para los includes de libft

all: $(NAME)

$(NAME): $(OBJS_PUSH_SWAP) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS_PUSH_SWAP) $(LIBFT_A) -o $(NAME)
	@echo "\033[0;32m✅ push_swap compilado! ✅\033[0m"

# Regla para construir libft.a
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