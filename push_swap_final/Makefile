NAME = push_swap
CHECKER_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

# Common source files (excluding main.c and checker_main.c)
COMMON_SRC_FILES = input_parsing.c \
				   stack_utils.c \
				   stack_operations.c \
				   stack_rotate_operations.c \
				   sorting_algorithms.c \
				   utils.c
COMMON_SRCS = $(addprefix $(SRC_DIR)/, $(COMMON_SRC_FILES))
COMMON_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(COMMON_SRCS))

# Push_swap specific files
PUSH_SWAP_MAIN_C = $(SRC_DIR)/main.c
#PUSH_SWAP_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(PUSH_SWAP_MAIN_C)) $(COMMON_OBJS)
# Simpler way for PUSH_SWAP_OBJS, using original SRCS and OBJS definitions for it
SRCS_PUSH_SWAP = $(PUSH_SWAP_MAIN_C) $(COMMON_SRCS)
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


# Checker specific files
CHECKER_MAIN_C = $(SRC_DIR)/checker_main.c
CHECKER_MAIN_O = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(CHECKER_MAIN_C))

# Aggregate objects for checker (GNL no longer used by checker_main.c directly)
CHECKER_OBJS = $(CHECKER_MAIN_O) $(COMMON_OBJS)


HEADERS = $(INC_DIR)/push_swap.h
# GNL_HEADER no longer needed here if GNL is not compiled as part of this Makefile

all: $(NAME) bonus

$(NAME): $(OBJS_PUSH_SWAP)
	$(CC) $(CFLAGS) $(OBJS_PUSH_SWAP) -o $(NAME)
	@echo "\033[0;32m✅ push_swap compiled! ✅\033[0m"

# Rule for checker executable (bonus part)
bonus: $(CHECKER_NAME)

$(CHECKER_NAME): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER_NAME)
	@echo "\033[0;32m✅ checker compiled! ✅\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# GNL compilation rule removed as GNL is not directly part of checker build process anymore from this Makefile

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) # Ensure OBJ_DIR is created before trying to compile into it

clean:
	rm -rf $(OBJ_DIR)
	@echo "\033[0;33m🧹 Object files removed 🧹\033[0m"

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKER_NAME)
	@echo "\033[0;33m🧹 Executables and object files removed 🧹\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus