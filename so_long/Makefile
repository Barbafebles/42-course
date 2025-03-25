NAME = so_long

CC = gcc 

CFLAGS = -Wall -Werror -Wextra

# Descomentar la línea del sistema operativo que estés usando
OS = MACOS
#OS = LINUX

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

SRC = src/check_map.c \

OBJ = $(SRC:.c=.o) 

all: mlx libft $(NAME)

mlx:
	@cmake $(MLX42_PATH) -B $(MLX42_PATH)/build
	@cmake --build $(MLX42_PATH)/build -j4

# Regla para compilar libft
libft:
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX42_LIB) $(LIBFT_LIB) $(MLX42_INCLUDE) $(LIBFT_INCLUDE) $(MLX_FLAGS) $(FRAMEWORKS) -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) $(MLX42_INCLUDE) $(LIBFT_INCLUDE) -c $< -o $@
 
clean: 
	rm -f $(OBJ)
	rm -rf $(MLX42_PATH)/build
	@make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all 

.PHONY: all clean fclean re mlx libft