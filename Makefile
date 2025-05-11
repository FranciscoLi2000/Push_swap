# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 00:31:10 by yufli             #+#    #+#              #
#    Updated: 2025/05/11 04:31:36 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile
NAME = push_swap

SRCS_DIR = srcs/
OBJS_DIR = objs/
INCS_DIR = includes/
LIBFT_DIR = libft/

SRCS = push_swap.c operations_a.c operations_b.c operations_both.c \
       small_sort.c radix_sort.c utils.c error.c index_conversion.c \
       parse_args.c

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

LIBFT = $(LIBFT_DIR)libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCS_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
