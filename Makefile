# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 19:26:58 by yufli             #+#    #+#              #
#    Updated: 2025/05/11 19:37:52 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

NAME			= push_swap

SRCS_DIR		= srcs
INCS_DIR		= includes
LIBFT_DIR		= libft

SRCS			= $(SRCS_DIR)/main.c $(SRCS_DIR)/chunk_sort.c \
			$(SRCS_DIR)/chunk_sort_utils.c \
			$(SRCS_DIR)/error_exit.c \
			$(SRCS_DIR)/five_sort.c \
			$(SRCS_DIR)/free_stacks.c \
			$(SRCS_DIR)/operations_a.c \
			$(SRCS_DIR)/operations_b.c \
			$(SRCS_DIR)/operations_both.c \
			$(SRCS_DIR)/parse_multiple_args.c \
			$(SRCS_DIR)/parse_single_arg.c \
			$(SRCS_DIR)/parse_single_arg_utils1.c \
			$(SRCS_DIR)/parse_single_arg_utils2.c \
			$(SRCS_DIR)/small_sort.c

OBJS			= $(SRCS:.c=.o)

LIBFT			= $(LIBFT_DIR)/libft.a

CC			= cc
CFLAGS			= -Wall -Wextra -Werror
INCLUDES		= -I$(INCS_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(LIBFT):
	@echo "$(BLUE)Compilando libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft compilada con éxito!$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compilando $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(PURPLE)Enlazando archivos objeto...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)$(NAME) compilado con éxito!$(RESET)"

clean:
	@echo "$(RED)Limpiando archivos objeto...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	@echo "$(GREEN)Archivos objeto eliminados.$(RESET)"

fclean: clean
	@echo "$(RED)Limpiando ejecutable...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(GREEN)$(NAME) eliminado.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
