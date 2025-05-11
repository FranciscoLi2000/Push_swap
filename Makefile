# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 00:31:10 by yufli             #+#    #+#              #
#    Updated: 2025/05/11 02:37:01 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRCS_DIR	= srcs/
OBJS_DIR	= objs/
INCS_DIR	= includes/

SRCS	= error_handle.c ft_strtol.c operations_a.c operations_both.c \
	push_swap.c small_sort.c ft_is_sorted.c index_conversion.c \
	operations_b.c parse_args.c radix_sort.c utils.c

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
