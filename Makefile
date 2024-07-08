# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 16:11:30 by ismherna          #+#    #+#              #
#    Updated: 2024/07/03 20:23:18 by ismherna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = minitalk
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Archivos
SRC_SERVER = src/server.c
SRC_CLIENT = src/client.c
SRC_SERVER_BONUS = src_bonus/server_bonus.c
SRC_CLIENT_BONUS = src_bonus/client_bonus.c

# Compilador y Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Regla para compilar la parte obligatoria
all: $(SERVER) $(CLIENT)
	@echo"minitalk ready"
	@echo " _____ ______    ___   ________    ___   _________   ________   ___        ___  __		"
	@echo "|\   _ \  _   \ |\  \ |\   ___  \ |\  \ |\___   ___\|\   __  \ |\  \      |\  \|\  \		"
	@echo "\ \  \\\__\ \  \\ \  \\ \  \\ \  \\ \  \\|___ \  \_|\ \  \|\  \\ \  \     \ \  \/  /|_		"
	@echo " \ \  \\|__| \  \\ \  \\ \  \\ \  \\ \  \    \ \  \  \ \   __  \\ \  \     \ \   ___  \		"
	@echo "  \ \  \    \ \  \\ \  \\ \  \\ \  \\ \  \    \ \  \  \ \  \ \  \\ \  \____ \ \  \\ \  \		"
	@echo "   \ \__\    \ \__\\ \__\\ \__\\ \__\\ \__\    \ \__\  \ \__\ \__\\ \_______\\ \__\\ \__\	"
	@echo "    \|__|     \|__| \|__| \|__| \|__| \|__|     \|__|   \|__|\|__| \|_______| \|__| \|__|	"
	@echo "											 		"
	@echo "				      2024/07/03 - ismherna@student.42.fr - 42 Madrid - Ismael Hernández"

$(SERVER): $(SRC_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): $(SRC_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@
	
# Regla para compilar los bonus
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(SRC_SERVER_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_BONUS): $(SRC_CLIENT_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

# Regla para compilar libft
$(LIBFT):
	@cd $(LIBFT_DIR) && make

# Regla para limpiar archivos objeto y ejecutables
clean:
	@cd $(LIBFT_DIR) && make clean
	@rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

# Regla para limpieza profunda
fclean: clean
	@cd $(LIBFT_DIR) && make fclean

# Regla para recompilar todo
re: fclean all

.PHONY: all clean fclean re bonus
