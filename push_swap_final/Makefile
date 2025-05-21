NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

SRCS = $(SRC_DIR)/main.c \
	   $(SRC_DIR)/input_parsing.c \
	   $(SRC_DIR)/stack_utils.c \
	   $(SRC_DIR)/stack_operations.c \
	   $(SRC_DIR)/stack_rotate_operations.c \
	   $(SRC_DIR)/sorting_algorithms.c \
	   $(SRC_DIR)/utils.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

HEADERS = $(INC_DIR)/push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;32m✅ Compilation complete. Push_swap is ready! ✅\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@echo "\033[0;33m🧹 Object files removed 🧹\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[0;33m🧹 Executable removed 🧹\033[0m"

re: fclean all

.PHONY: all clean fclean re