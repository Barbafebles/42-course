
	# Library name # 
SERVER = server
CLIENT = client
SERVER = 

	# libft and printf #
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/ft_printf.a

	# Library variables #
SRC_CLIENT = client.c 
SRC_SERVER = server.c

	# Compiling variables # 
cc = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f


all: $(SERVER) $(CLIENT)

$(SERVER): $(SRC_SERVER)
	$(CC) $(CFLAGS) -o $(SERVER) $(SRC_SERVER) $(LIBFT) $(PRINTF)

$(CLIENT): $(SRC_CLIENT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(SRC_CLIENT) $(LIBFT) $(PRINTF)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

