NAME = pipex

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SOURCE = pipex.c utils.c Funciones_learn.c
OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
.PHONY: all clean fclean re