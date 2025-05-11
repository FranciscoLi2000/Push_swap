# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 00:31:10 by yufli             #+#    #+#              #
#    Updated: 2025/05/11 10:06:33 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile
NAME = push_swap

SRCS_DIR = srcs/
OBJS_DIR = objs/
INCS_DIR = includes/
LIBFT_DIR = libft/

SRCS = push_swap.c operations_a.c operations_b.c operations_both.c \
       small_sort.c radix_sort.c utils.c error.c index_conversion.c parse_args.c

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
