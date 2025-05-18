# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 07:28:28 by yufli             #+#    #+#              #
#    Updated: 2025/05/18 23:34:33 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilador i flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Iincludes

# Carpetes
SRC_DIR     = srcs
LIBFT_DIR   = libft

# Output
NAME    = push_swap

# Arxius font
SRC_FILES   = $(wildcard $(SRC_DIR)/*.c)
LIBFT_FILES = $(wildcard $(LIBFT_DIR)/*.c)
SRCS        = $(SRC_FILES) $(LIBFT_FILES)
OBJS        = $(SRCS:.c=.o)

# Colors
GREEN   = \033[0;32m
RESET   = \033[0m

# Regles
all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compilant $(NAME)..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	@echo "Netegem objectes..."
	rm -f $(OBJS)

fclean: clean
	@echo "Esborrem executable..."
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
