# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 14:56:35 by bfebles-          #+#    #+#              #
#    Updated: 2025/05/20 14:56:39 by bfebles-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc 

CFLAGS = -Wall -Werror -Wextra

# Descomentar la línea del sistema operativo que estés usando
#OS = MACOS
OS = LINUX

# Configuración para macOS
ifeq ($(OS), MACOS)
    FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit
    MLX_FLAGS = -lglfw -L"/opt/homebrew/opt/glfw/lib"
endif

# Configuración para Linux
ifeq ($(OS), LINUX)
    FRAMEWORKS =
    MLX_FLAGS = -ldl -lglfw -pthread -lm
endif

MLX42_PATH = MLX42
MLX42_LIB = $(MLX42_PATH)/build/libmlx42.a
MLX42_INCLUDE = -I $(MLX42_PATH)/include

# Añadir libft
LIBFT_PATH = libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a
LIBFT_INCLUDE = -I $(LIBFT_PATH)
FT_PRINTF_PATH = ft_printf
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a
FT_PRINTF_INCLUDE = -I $(FT_PRINTF_PATH)


SRC = 	src/error_handling.c src/map_load.c src/map_file.c src/map_count.c src/map_validate_basic.c \
		src/map_validate_path.c src/map_validate_size.c src/validate_map_complete.c src/path_finding.c \
		src/utils.c src/windows.c src/textures.c src/render_map.c src/render_utils.c src/hook.c \
		src/movement.c\


OBJ = $(SRC:.c=.o) 

all: mlx libft $(NAME)

mlx:
	@cmake $(MLX42_PATH) -B $(MLX42_PATH)/build
	@cmake --build $(MLX42_PATH)/build -j4

# Regla para compilar libft
libft:
	@make -C $(LIBFT_PATH)
	@make -C $(FT_PRINTF_PATH)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX42_LIB) $(LIBFT_LIB) $(FT_PRINTF) $(MLX42_INCLUDE) $(LIBFT_INCLUDE) $(FT_PRINTF_INCLUDE) $(MLX_FLAGS) $(FRAMEWORKS) -o $(NAME)


%.o: %.c 
	$(CC) $(CFLAGS) $(MLX42_INCLUDE) $(LIBFT_INCLUDE) $(FT_PRINTF_INCLUDE) -c $< -o $@



 
clean: 
	rm -f $(OBJ)
	rm -rf $(MLX42_PATH)/build
	@make -C $(LIBFT_PATH) clean
	@make -C $(FT_PRINTF_PATH) clean



fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(FT_PRINTF_PATH) fclean


re: fclean all 

.PHONY: all clean fclean re mlx libft