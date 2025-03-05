
NAME = so_long

CC = gcc 

CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"

MLX42_PATH = MLX42
MLX42_LIB = $(MLX42_PATH)/build/libmlx42.a
MLX42_INCLUDE = -I $(MLX42_PATH)/include

SRC = prueba.c

OBJ = $(SRC:.c=.o) 

all: mlx $(NAME)

mlx:
	@cmake $(MLX42_PATH) -B $(MLX42_PATH)/build
	@cmake --build $(MLX42_PATH)/build -j4

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX42_LIB) $(MLX42_INCLUDE) $(MLX_FLAGS) -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) $(MLX42_INCLUDE) -c $< -o $@
 
clean: 
	rm -f $(OBJ)
	rm -rf $(MLX42_PATH)/build

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re mlx