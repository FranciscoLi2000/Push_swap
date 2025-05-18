# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 19:48:25 by yufli             #+#    #+#              #
#    Updated: 2025/05/18 05:55:26 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC		= cc
CFLAGS		= -Wall -Wextra -Werror -Iincludes

SRCDIR		= srcs
OBJDIR		= objs

SRCFILES	= \
	ft_split.c \
	parse_multiple_args.c \
	rotate.c \
	stack_utils.c \
	ft_strchr.c \
	ft_strlcpy.c \
	parse_single_arg.c \
	sort_three.c \
	swap.c \
	input_validation.c \
	push.c \
	sort_two.c \
	main.c \
	reverse_rotate.c \
	sort_five.c \
	stack.c \
	sort_radix.c \
	sort_radix_utils.c \
	sort_insertion.c \
	sort_butterfly.c

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
