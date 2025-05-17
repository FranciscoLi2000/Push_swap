# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 19:48:25 by yufli             #+#    #+#              #
#    Updated: 2025/05/17 19:49:20 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC		= cc
CFLAGS		= -Wall -Wextra -Werror -Iincludes

SRCDIR		= srcs
OBJDIR		= objs

SRCFILES	= \
	main.c \
	ft_split.c \
	ft_strchr.c \
	ft_strlcpy.c \
	parse_single_arg.c \
	parse_multiple_args.c \
	print_stack.c \
	stack.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	sort_two.c \
	sort_three.c \
	sort_five.c \
	sort_insertion.c \
	sort_chunk.c \
	sort_chunk_utils.c \
	sort_radix.c

SRC			= $(addprefix $(SRCDIR)/, $(SRCFILES))
OBJ			= $(addprefix $(OBJDIR)/, $(SRCFILES:.c=.o))

GREEN	= \033[0;32m
RESET	= \033[0m

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✅ Compiled $(NAME)$(RESET)"

clean:
	@rm -rf $(OBJDIR)
	@echo "🧹 Cleaned object files"

fclean: clean
	@rm -f $(NAME)
	@echo "🧹🧹 Fully cleaned"

re: fclean all

.PHONY: all clean fclean re
