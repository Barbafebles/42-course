NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./src

# Define directories for sources and objects
SRCS_DIR = src/
OBJS_DIR = obj/

# Source files list
SRCS = $(SRCS_DIR)main.c \
       $(SRCS_DIR)stack_ops.c \
       $(SRCS_DIR)stack_utils.c \
       $(SRCS_DIR)sort.c \
       $(SRCS_DIR)utils.c

# Generate object files list
OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

# Object files compilation
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Default target
all: $(NAME)

# Clean object files
clean:
	rm -rf $(OBJS_DIR)

# Full clean
fclean: clean
	rm -f $(NAME)

# Complete rebuild
re: fclean all

.PHONY: all clean fclean re