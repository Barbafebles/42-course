NAME = pipex // nombre de mi archivo 

CC = gcc // compilador 

CFLAGS = -Wall -Werror -Wextra // flags para compilar 

SOURCE = pipex.c utils.c protect.c // funciones 
OBJ = $(SOURCE:.c=.o) // regla para establecer los .o

LIBFT_DIREC = /home/barbafebles/Desktop/42-course/pipex/libft // la ruta de libft
LIBFT = $(LIBFT_DIREC)/libft.a // la ejecucion del .a 

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -l./libft 

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean: 
	@rm -f $(OBJ)
	make -C libft clean

fclean: clean
	@rm -f $(NAME)
	make -C libft fclean

re:	fclean all
.PHONY: all clean fclean re
