NAME = pipex

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SOURCE = pipex.c utils.c protect.c
OBJ = $(SOURCE:.c=.o)
#cambiarle la ruta de linux o macOS
LIBFT_DIREC = /Users/barbarafebles/Desktop/42/42-course/pipex/libft
LIBFT = $(LIBFT_DIREC)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIREC) -lft

#	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -l./libft 

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIREC)

clean: 
	@rm -f $(OBJ)
	make -C libft clean

fclean: clean
	@rm -f $(NAME)
	make -C $(LIBFT_DIREC) fclean

re:	fclean all
.PHONY: all clean fclean re
