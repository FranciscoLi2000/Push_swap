# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 19:22:58 by yufli             #+#    #+#              #
#    Updated: 2025/05/13 19:30:35 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	= \033[0;32m
YELLOW	= \033[0;33m
RED	= \033[0;31m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
RESET	= \033[0m

NAME		= push_swap
SRCS_DIR	= srcs
INCS_DIR	= includes
LIBFT_DIR	= libft

SRCS		= $(SRCS_DIR)/main.c \
		$(SRCS_DIR)/utils.c \
		$(SRCS_DIR)/parse_args.c \
		$(SRCS_DIR)/parse_single_arg.c \
		$(SRCS_DIR)/parse_multiple_args.c \
		$(SRCS_DIR)/normalize.c \
		$(SRCS_DIR)/operations_a.c \
		$(SRCS_DIR)/operations_b.c \
		$(SRCS_DIR)/operations_both.c \
		$(SRCS_DIR)/find_utils.c \
		$(SRCS_DIR)/small_sort.c \
		$(SRCS_DIR)/five_sort.c \
		$(SRCS_DIR)/chunk_sort_100.c \
		$(SRCS_DIR)/chunk_sort_500.c \
		$(SRCS_DIR)/execute_sort.c

OBJS		= $(SRCS:.c=.o)

LIBFT		= $(LIBFT_DIR)/libft.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I$(INCS_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft compiled successfully!$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(PURPLE)Relating object files...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

clean:
	@echo "$(RED)Removing object files...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	@echo "$(GREEN)Object files removed.$(RESET)"

fclean: clean
	@echo "$(RED)Removing executed program...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(GREEN)$(NAME) removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
