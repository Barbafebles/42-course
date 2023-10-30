
NAME = push_swap.a
CC = gcc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = 
	

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@	

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
