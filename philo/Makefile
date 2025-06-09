# Variables
NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread -g
INCLUDES	= -I includes/
SRCS_DIR	= srcs/
OBJS_DIR	= objs/

# Source files - list all .c files here
SRCS_FILES	= main.c \
			  args.c \
			  init.c \
			  utils.c \
			  actions.c \
			  routine.c \
			  monitor.c \
			  cleanup.c

# Generate full source paths
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

# Generate object file paths
OBJS		= $(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))

# Commands
RM			= rm -f
RMDIR		= rm -rf

# Default rule
all: $(NAME)

# Linker rule: create executable from object files
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compiler rule: create object files from source files
# Depends on the source file, the main header, and the Makefile itself.
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c includes/philo.h Makefile
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean rule: remove object directory
clean:
	$(RMDIR) $(OBJS_DIR)

# Full clean rule: clean object files and the executable
fclean: clean
	$(RM) $(NAME)

# Rebuild rule: full clean then build
re: fclean all

# Phony targets
.PHONY: all clean fclean re
