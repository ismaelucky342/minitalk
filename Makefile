SERVER = server
CLIENT = client

CFLAGS = -Wall -Werror -Wextra
CC = gcc
FLAGS = -Wall -Wextra -Werror -I$(LIBFT)/headers -L$(LIBFT) -l:libft.a

LIBFT = libft

all:
	@make -s -C $(LIBFT)
	@gcc $(FLAGS) server.c -o $(SERVER)
	@gcc $(FLAGS) client.c -o $(CLIENT)
	@echo "Server/Client Ready!"

clean:
	@make clean -s -C $(LIBFT)

fclean: clean
	@make fclean -s -C $(LIBFT)
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server/Client Deleted"

re: fclean all